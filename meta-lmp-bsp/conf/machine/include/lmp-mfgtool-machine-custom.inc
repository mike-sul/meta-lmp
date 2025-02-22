# Embedded Artists i.MX7ULP COM
UBOOT_SIGN_ENABLE:imx7ulpea-ucom = "1"
PREFERRED_PROVIDER_virtual/kernel:imx7ulpea-ucom = "linux-lmp-dev-mfgtool"
KERNEL_REPO:imx7ulpea-ucom ?= "git://github.com/foundriesio/linux.git"
LINUX_VERSION:imx7ulpea-ucom ?= "5.10.y"
KERNEL_BRANCH:imx7ulpea-ucom ?= "linux-ea-v5.10.y"
KERNEL_COMMIT:imx7ulpea-ucom ?= "4026a5c637c4237dabffbaea1c1b38fddcf73fba"
PREFERRED_PROVIDER_virtual/bootloader:imx7ulpea-ucom = "u-boot-fio-mfgtool"
PREFERRED_PROVIDER_u-boot:imx7ulpea-ucom = "u-boot-fio-mfgtool"
PREFERRED_PROVIDER_u-boot-default-script:imx7ulpea-ucom = "u-boot-ostree-scr-fit"
UBOOT_CLASSES:imx7ulpea-ucom = "uboot-fitimage"
IMAGE_BOOT_FILES:imx7ulpea-ucom = "boot.itb SPL u-boot.itb"
KERNEL_IMAGETYPE:imx7ulpea-ucom = "fitImage"
KERNEL_CLASSES:imx7ulpea-ucom = " kernel-lmp-fitimage "

# iMX6UL
UBOOT_SIGN_ENABLE:mx6ul-generic-bsp = "1"
PREFERRED_PROVIDER_virtual/kernel:mx6ul-nxp-bsp = "linux-lmp-dev-mfgtool"
IMX_DEFAULT_BOOTLOADER:mx6ul-generic-bsp ?= "u-boot-fio-mfgtool"
PREFERRED_PROVIDER_u-boot-default-script:mx6ul-generic-bsp = "u-boot-ostree-scr-fit"
UBOOT_CLASSES:mx6ul-generic-bsp = "uboot-fitimage"
IMAGE_BOOT_FILES:remove:mx6ul-generic-bsp = "boot.scr uEnv.txt zImage"
IMAGE_BOOT_FILES:append:mx6ul-generic-bsp = " boot.itb SPL u-boot.itb"
KERNEL_IMAGETYPE:mx6ul-generic-bsp = "fitImage"
KERNEL_CLASSES:mx6ul-generic-bsp = " kernel-lmp-fitimage "

# iMX6ULL
UBOOT_SIGN_ENABLE:mx6ull-generic-bsp = "1"
PREFERRED_PROVIDER_virtual/kernel:mx6ull-nxp-bsp = "linux-lmp-dev-mfgtool"
IMX_DEFAULT_BOOTLOADER:mx6ull-generic-bsp ?= "u-boot-fio-mfgtool"
PREFERRED_PROVIDER_u-boot-default-script:mx6ull-generic-bsp = "u-boot-ostree-scr-fit"
UBOOT_CLASSES:mx6ull-generic-bsp = "uboot-fitimage"
IMAGE_BOOT_FILES:remove:mx6ull-generic-bsp = "boot.scr uEnv.txt zImage"
IMAGE_BOOT_FILES:append:mx6ull-generic-bsp = " boot.itb SPL u-boot.itb"
KERNEL_IMAGETYPE:mx6ull-generic-bsp = "fitImage"
KERNEL_CLASSES:mx6ull-generic-bsp = " kernel-lmp-fitimage "

# iMX8MQ
UBOOT_SIGN_ENABLE:mx8mq-generic-bsp = "1"
PREFERRED_PROVIDER_virtual/kernel:mx8mq-nxp-bsp = "linux-lmp-dev-mfgtool"
IMX_DEFAULT_BOOTLOADER:mx8mq-generic-bsp ?= "u-boot-fio-mfgtool"
PREFERRED_PROVIDER_u-boot-default-script:mx8mq-generic-bsp = "u-boot-ostree-scr-fit"
IMAGE_BOOT_FILES:mx8mq-nxp-bsp  = "imx-boot u-boot.itb boot.itb"
KERNEL_IMAGETYPE:mx8mq-generic-bsp = "fitImage"
KERNEL_CLASSES:mx8mq-generic-bsp = " kernel-lmp-fitimage "

# iMX8MPEVK
UBOOT_SIGN_ENABLE:mx8mp-generic-bsp = "1"
IMX_DEFAULT_BOOTLOADER:mx8mp-generic-bsp ?= "u-boot-fio-mfgtool"
PREFERRED_PROVIDER_u-boot-default-script:mx8mp-generic-bsp = "u-boot-ostree-scr"
IMAGE_BOOT_FILES:mx8mp-nxp-bsp  = "imx-boot u-boot.itb boot.itb"
KERNEL_IMAGETYPE:mx8mp-generic-bsp = "fitImage"
KERNEL_CLASSES:mx8mp-generic-bsp = " kernel-lmp-fitimage "

# iMX8MM
UBOOT_SIGN_ENABLE:mx8mm-generic-bsp = "1"
IMX_DEFAULT_BOOTLOADER:mx8mm-generic-bsp ?= "u-boot-fio-mfgtool"
PREFERRED_PROVIDER_u-boot-default-script:mx8mm-generic-bsp = "u-boot-ostree-scr"
IMAGE_BOOT_FILES:mx8mm-nxp-bsp  = "imx-boot u-boot.itb boot.itb"
KERNEL_IMAGETYPE:mx8mm-generic-bsp = "fitImage"
KERNEL_CLASSES:mx8mm-generic-bsp = " kernel-lmp-fitimage "

# Apalis-iMX6
UBOOT_SIGN_ENABLE:apalis-imx6 = "1"
PREFERRED_PROVIDER_virtual/kernel:apalis-imx6 = "linux-lmp-dev-mfgtool"
IMX_DEFAULT_BOOTLOADER:apalis-imx6 ?= "u-boot-fio-mfgtool"
PREFERRED_PROVIDER_u-boot-default-script:apalis-imx6 = "u-boot-ostree-scr-fit"
UBOOT_CLASSES:apalis-imx6 = "uboot-fitimage"
IMAGE_BOOT_FILES:apalis-imx6 = "boot.itb SPL u-boot.itb"
KERNEL_IMAGETYPE:apalis-imx6 = "fitImage"
KERNEL_CLASSES:apalis-imx6 = " kernel-lmp-fitimage "

# iMX8QM-MEK and Apalis-iMX8
IMX_DEFAULT_BOOTLOADER:mx8qm-generic-bsp ?= "u-boot-fio-mfgtool"
PREFERRED_PROVIDER_u-boot-default-script:mx8qm-generic-bsp = "u-boot-ostree-scr-fit"
KERNEL_IMAGETYPE:mx8qm-generic-bsp = "fitImage"
KERNEL_CLASSES:mx8qm-generic-bsp = " kernel-lmp-fitimage "
UBOOT_SIGN_ENABLE:mx8qm-generic-bsp = "1"
UBOOT_CLASSES:mx8qm-generic-bsp = "uboot-fitimage"
IMAGE_BOOT_FILES:mx8qm-nxp-bsp  = "imx-boot u-boot.itb boot.itb"
