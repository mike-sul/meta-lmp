DISTRO_VERSION = "4.0.1"

# These default to 'oecore' and 'nodistro'
SDK_NAME_PREFIX = "${DISTRO}"
SDK_VERSION = "${DISTRO_VERSION}"

MAINTAINER = "LMP Support <support@foundries.io>"

TARGET_VENDOR = "-lmp"

TCLIBCAPPEND = ""

require conf/distro/include/arm-defaults.inc
require conf/distro/include/security_flags.inc

PREFERRED_PROVIDER_virtual/kernel ?= "linux-lmp"
PREFERRED_PROVIDER_virtual/optee-os ?= "optee-os-fio"
PREFERRED_PROVIDER_u-boot-fw-utils ?= "libubootenv"
PREFERRED_RPROVIDER_u-boot-fw-utils ?= "libubootenv"
PREFERRED_PROVIDER_zlib ?= "zlib"
PREFERRED_PROVIDER_zlib-native ?= "zlib-native"
PREFERRED_PROVIDER_nativesdk-zlib ?= "nativesdk-zlib"
PREFERRED_PROVIDER_qemu-native ?= "qemu-native"
PREFERRED_PROVIDER_qemu-helper-native ?= "qemu-helper-native"
PREFERRED_PROVIDER_nativesdk-qemu ?= "nativesdk-qemu"
PREFERRED_PROVIDER_virtual/docker = "docker-ce"

PREFERRED_VERSION_gcc-arm-none-eabi ?= "10.3-2021.10"
PREFERRED_VERSION_gcc-arm-none-eabi-native ?= "10.3-2021.10"

# Default distro features for LMP (can be extended by the user if needed)
INIT_MANAGER = "systemd"
DISTRO_FEATURES_DEFAULT = "acl argp bluetooth ext2 ipv4 ipv6 largefile usbgadget usbhost wifi xattr zeroconf pci vfat modsign efi security tpm integrity seccomp"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "pulseaudio ldconfig"
DISTRO_FEATURES:append = " pam usrmerge virtualization ptest"

# Default IMA policy (tcb)
IMA_POLICY ?= "ima-policy-tcb"

# Extended packageconfig options for LMP
PACKAGECONFIG:append:pn-docker-ce = " seccomp"
PACKAGECONFIG:append:pn-docker-moby = " seccomp"
# Required because of https://github.com/opencontainers/runc/issues/2008
PACKAGECONFIG:remove:pn-runc-opencontainers = "static"
PACKAGECONFIG:append:pn-qemu-native = " libusb"
PACKAGECONFIG:append:pn-networkmanager = " libedit"
PACKAGECONFIG:remove:pn-networkmanager = " readline"

# Alternatives used by nss-altfiles
NSS_ALT_TYPES ?= "hosts,pwd,grp,spwd,sgrp"
# Unix users that will be mirrored in /etc/passwd to allow manipulation
ETC_PASSWD_MEMBERS ?= "${LMP_USER}"
# Unix groups that will be mirrored in /etc/group to allow manipulation
ETC_GROUP_MEMBERS ?= "sudo audio video plugdev users docker"

# Use staticids for deterministic uid/gid values
USERADDEXTENSION = "useradd-staticids"
USERADD_UID_TABLES = "files/lmp-passwd-table"
USERADD_GID_TABLES = "files/lmp-group-table"
USERADD_ERROR_DYNAMIC = "error"

# Default image formats
IMAGE_FSTYPES = "wic wic.gz wic.bmap"
IMAGE_FSTYPES:remove = "tar.gz tar.bz2"

# No Ostree tarball by default (prefer ota instead)
BUILD_OSTREE_TARBALL ?= "0"

# LMP default classes and overwrites
INHERIT += "lmp"

INHERIT += "buildhistory"
INHERIT += "image-buildinfo"
BUILDHISTORY_COMMIT = "1"

PREMIRRORS ??= "\
     git://.*/.* https://storage.googleapis.com/lmp-cache/downloads/ \n \
     ftp://.*/.* https://storage.googleapis.com/lmp-cache/downloads/ \n \
     http://.*/.* https://storage.googleapis.com/lmp-cache/downloads/ \n \
     https://.*/.* https://storage.googleapis.com/lmp-cache/downloads/ \n \
"

MIRRORS =+ "\
     ftp://.*/.* https://storage.googleapis.com/lmp-cache/downloads/ \n \
     http://.*/.* https://storage.googleapis.com/lmp-cache/downloads/ \n \
     https://.*/.* https://storage.googleapis.com/lmp-cache/downloads/ \n \
"

# Compatibility with other layers
BBMASK += " \
    /meta-virtualization/recipes-kernel/linux/linux-%.bbappend \
    /meta-virtualization/dynamic-layers/xilinx/recipes-extended/xen/xen_4.14.bbappend \
    /meta-security/meta-integrity/recipes-core/systemd/systemd_%.bbappend \
    /meta-updater/recipes-connectivity/nfs-utils/nfs-utils_%.bbappend \
"

# meta-xilinx/meta-xilinx-tools: mask recipes not required for lmp
BBMASK += " \
    /meta-xilinx-tools/recipes-bsp/ai-engine/aiefal_1.0.bb \
    /meta-xilinx-tools/recipes-bsp/u-boot/u-boot-xlnx_%.bbappend \
"

# disable xsct tarball by default (xilinx)
USE_XSCT_TARBALL = "0"

# QA check settings - follow poky, which is stricter than the OE-Core defaults
WARN_TO_ERROR_QA = "already-stripped compile-host-path install-host-path \
                    installed-vs-shipped ldflags pn-overrides rpaths staticdev \
                    unknown-configure-option useless-rpaths"
WARN_QA:remove = "${WARN_TO_ERROR_QA}"
ERROR_QA:append = " ${WARN_TO_ERROR_QA}"
ERROR_QA:remove = "version-going-backwards"

LMP_USER ?= "fio"
# LMP_PASSWORD is a hassed password. To generate the hash use the following command on a host machine
# mkpasswd -m sha512crypt
# When copy and pasting the hash, remember to escape any $ character as in the following example
LMP_PASSWORD ?= "\$6\$OxIhuUvtdFqmUyLv\$gnwD.Qz53y.hvkLc5LyClP8MSRMtG8VZHz.qg/OvRep93ls.2CGzYvINCOrdXYU4yi1q394gWXqixRxO9yCSU/"
