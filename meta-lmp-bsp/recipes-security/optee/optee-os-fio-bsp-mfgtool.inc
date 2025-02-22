OPTEEMACHINE:apalis-imx6 = "imx-mx6qapalis"
OPTEEMACHINE:apalis-imx8 = "imx-mx8qmmek"
OPTEEMACHINE:imx6ulevk = "imx-mx6ulevk"
OPTEEMACHINE:imx6ullevk = "imx-mx6ullevk"
OPTEEMACHINE:imx7ulpea-ucom = "imx-mx7ulpevk"
OPTEEMACHINE:imx8mm-lpddr4-evk = "imx-mx8mmevk"
OPTEEMACHINE:imx8mp-lpddr4-evk = "imx-mx8mpevk"
OPTEEMACHINE:imx8mq-evk = "imx-mx8mqevk"
OPTEEMACHINE:imx8qm-mek = "imx-mx8qmmek"

# SoC Settings
EXTRA_OEMAKE:append:mx8m-nxp-bsp = " \
    CFG_NXP_CAAM=y CFG_NXP_CAAM_RNG_DRV=y \
    CFG_WITH_SOFTWARE_PRNG=n CFG_CRYPTO_DRIVER=y CFG_RNG_PTA=y \
    CFG_DT=y CFG_EXTERNAL_DTB_OVERLAY=y CFG_DT_ADDR=0x43200000 \
"
EXTRA_OEMAKE:append:mx8qm-nxp-bsp = " \
    CFG_DT=y CFG_EXTERNAL_DTB_OVERLAY=y CFG_DT_ADDR=0x83200000 \
"

# Machine Settings
EXTRA_OEMAKE:append:apalis-imx6 = " \
    CFG_NS_ENTRY_ADDR=0x17800000 CFG_NXP_CAAM=y CFG_CRYPTO_DRIVER=y CFG_RNG_PTA=y \
    CFG_TZDRAM_START=0x4e000000 CFG_DT=y CFG_OVERLAY_ADDR=0x16000000 \
"
EXTRA_OEMAKE:append:apalis-imx8 = " \
    CFG_UART_BASE=0x5a070000 \
    CFG_NXP_CAAM=y CFG_NXP_CAAM_RNG_DRV=y \
    CFG_WITH_SOFTWARE_PRNG=n CFG_CRYPTO_DRIVER=y CFG_RNG_PTA=y \
"
EXTRA_OEMAKE:append:imx6ulevk = " \
    CFG_NS_ENTRY_ADDR=0x87800000 CFG_NXP_CAAM=y CFG_NXP_CAAM_RNG_DRV=y \
    CFG_WITH_SOFTWARE_PRNG=n CFG_CRYPTO_DRIVER=y \
    CFG_TZDRAM_START=0x9e000000 CFG_DT=y CFG_OVERLAY_ADDR=0x86000000 \
"
EXTRA_OEMAKE:append:imx6ullevk = " \
    CFG_NS_ENTRY_ADDR=0x87800000 CFG_TZDRAM_START=0x9e000000 \
    CFG_WITH_SOFTWARE_PRNG=n CFG_IMX_RNGB=y CFG_RNG_PTA=y \
    CFG_DT=y CFG_OVERLAY_ADDR=0x86000000 \
"
EXTRA_OEMAKE:append:imx7ulpea-ucom = " \
    CFG_RNG_PTA=y CFG_DRAM_BASE=0x60000000 CFG_NS_ENTRY_ADDR=0x67800000 \
    CFG_TZDRAM_START=0x9e000000 CFG_DT=y CFG_OVERLAY_ADDR=0x65000000 \
    CFG_NXP_WORKAROUND_CAAM_LOCKED_BY_HAB=y \
"
EXTRA_OEMAKE:append:imx8mp-lpddr4-evk = " \
    CFG_TZDRAM_START=0x56000000 \
"

# Additional Settings for SE05X
EXTRA_OEMAKE:append:imx6ullevk = " \
    ${@bb.utils.contains('MACHINE_FEATURES', 'se05x', 'CFG_IMX_I2C=y CFG_CORE_SE05X_I2C_BUS=1', '', d)} \
"
EXTRA_OEMAKE:append:imx8mm-lpddr4-evk = " \
    ${@bb.utils.contains('MACHINE_FEATURES', 'se05x', 'CFG_IMX_I2C=y CFG_CORE_SE05X_I2C_BUS=2', '', d)} \
"
EXTRA_OEMAKE:append:imx8mp-lpddr4-evk = " \
    ${@bb.utils.contains('MACHINE_FEATURES', 'se05x', 'CFG_IMX_I2C=y CFG_CORE_SE05X_I2C_BUS=4', '', d)} \
"

# Extra Settings for Secure Machines
EXTRA_OEMAKE:append:apalis-imx6-sec = " \
    CFG_REE_FS=n CFG_RPMB_FS=y CFG_RPMB_WRITE_KEY=y \
"
EXTRA_OEMAKE:append:apalis-imx8-sec = " \
    CFG_REE_FS=n CFG_RPMB_FS=y CFG_RPMB_FS_DEV_ID=0 CFG_RPMB_WRITE_KEY=y \
"
EXTRA_OEMAKE:append:imx8mm-lpddr4-evk-sec = " \
    CFG_REE_FS=n CFG_RPMB_FS=y CFG_RPMB_WRITE_KEY=y CFG_RPMB_FS_DEV_ID=2 \
"
EXTRA_OEMAKE:append:imx8mp-lpddr4-evk-sec = " \
    CFG_REE_FS=n CFG_RPMB_FS=y CFG_RPMB_WRITE_KEY=y CFG_RPMB_FS_DEV_ID=2 \
"
