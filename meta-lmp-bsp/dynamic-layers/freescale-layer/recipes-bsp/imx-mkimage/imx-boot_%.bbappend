FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

DEPENDS:remove = "optee-os"
DEPENDS += "${@bb.utils.contains('MACHINE_FEATURES', 'optee', 'virtual/optee-os', '', d)}"

SRC_URI:remove = " file://0001-mkimage_fit_atf-fix-fit-generator-node-naming.patch"

SRC_URI:append:mx8m-nxp-bsp = " \
     file://0002-iMX8M-add-SPL-only-build.patch \
     file://0003-iMX8M-add-support-for-packing-HDMI-fw-in-SPL-only-bo.patch \
     file://0004-iMX8M-also-create-nohdmi-boot-image.patch \
     file://0001-iMX8M-change-DDR-DMEM-padding.patch \
"

SRC_URI:append:mx8qm-nxp-bsp = " \
     file://0001-iMX8QM-add-SPL-only-build.patch \
"

do_compile[depends] = " \
    virtual/bootloader:do_deploy \
    ${@' '.join('%s:do_deploy' % r for r in '${IMX_EXTRA_FIRMWARE}'.split() )} \
    imx-atf:do_deploy \
    ${@bb.utils.contains('MACHINE_FEATURES', 'optee', 'virtual/optee-os:do_deploy', '', d)} \
"

do_compile:prepend:mx8-nxp-bsp() {
    for target in ${IMXBOOT_TARGETS}; do
        if [ "${target}" = "flash_evk_spl" ]; then
            # copy u-boot-spl-nodtb instead of u-boot-spl.bin as we need to have
            # spl and its dtb separate (dt-spl.dtb will contain public hash of
            # used to check the signature of u-boot fit-image)
            cp ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/u-boot-spl-nodtb.bin-${MACHINE}-${UBOOT_CONFIG} \
                                                                 ${BOOT_STAGING}/u-boot-spl-nodtb.bin
            cp ${DEPLOY_DIR_IMAGE}/u-boot-spl.bin-${MACHINE}.dtb ${BOOT_STAGING}/u-boot-spl.dtb
            if [ -e "${DEPLOY_DIR_IMAGE}/signed_hdmi_imx8m.bin" ]; then
                cp ${DEPLOY_DIR_IMAGE}/signed_hdmi_imx8m.bin ${BOOT_STAGING}/signed_hdmi_imx8m.bin
            fi
        fi
    done
}

do_compile:append() {
    for target in ${IMXBOOT_TARGETS}; do
        if [ "${target}" = "flash_evk_spl" ]; then
            if [ -e "${BOOT_STAGING}/flash.bin-nohdmi" ]; then
                cp ${BOOT_STAGING}/flash.bin-nohdmi ${S}/${BOOT_CONFIG_MACHINE}-${target}-nohdmi
            fi
        fi
    done
}

do_install:append() {
    for target in ${IMXBOOT_TARGETS}; do
        if [ "${target}" = "flash_evk_spl" ]; then
            if [ -e "${S}/${BOOT_CONFIG_MACHINE}-${target}-nohdmi" ]; then
                install -m 0644 ${S}/${BOOT_CONFIG_MACHINE}-${target}-nohdmi ${D}/boot/
            fi
        fi
    done
}

do_deploy:append() {
    for target in ${IMXBOOT_TARGETS}; do
        if [ "${target}" = "flash_evk_spl" ]; then
            # Also create imx-boot link with the machine name
            if [ ! -e "${DEPLOYDIR}/${BOOT_NAME}-${MACHINE}" ]; then
                ln -sf ${BOOT_CONFIG_MACHINE}-${target} ${DEPLOYDIR}/${BOOT_NAME}-${MACHINE}
            fi
            if [ -e "${S}/${BOOT_CONFIG_MACHINE}-${target}-nohdmi" ]; then
                install -m 0644 ${S}/${BOOT_CONFIG_MACHINE}-${target}-nohdmi ${DEPLOYDIR}
                ln -sf ${BOOT_CONFIG_MACHINE}-${target}-nohdmi \
		    ${DEPLOYDIR}/${BOOT_NAME}-${MACHINE}-nohdmi
                ln -sf ${BOOT_CONFIG_MACHINE}-${target}-nohdmi \
		    ${DEPLOYDIR}/${BOOT_NAME}-nohdmi
            fi
        fi
    done
}
