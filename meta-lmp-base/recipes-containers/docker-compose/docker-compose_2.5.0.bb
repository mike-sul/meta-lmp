HOMEPAGE = "https://github.com/docker/compose"
SUMMARY = "Define and run multi-container applications with Docker"
DESCRIPTION = "Docker Compose is a tool for running multi-container \
 applications on Docker defined using the Compose file format."
SECTION = "devel"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://src/${GO_IMPORT}/LICENSE;md5=175792518e4ac015ab6696d16c4f607e"

SRC_URI = "\
	git://github.com/docker/compose.git;branch=v2;protocol=https;name=compose \
	git://github.com/docker/cli.git;branch=master;protocol=https;name=cli;destsuffix=${S}/src/github.com/docker/cli \
	file://cli-config-support-default-system-config.patch \
	"

SRCREV_compose = "41b3967cb521a7c7254155a70fbafa5f5ae02aad"
SRCREV_cli = "2b52f62e962783ef39b53d1cb95e1d435b33f3cd"

UPSTREAM_CHECK_COMMITS = "1"

GO_IMPORT = "github.com/docker/compose/v2"

inherit go-mod

GO_EXTRA_LDFLAGS = "-w -X ${GO_IMPORT}/internal.Version=${PV}"

go_do_compile() {
	export TMPDIR="${GOTMPDIR}"
	mkdir -p ${B}/cli-plugins/bin
	${GO} mod download -modcacherw
	cp -f ${S}/src/github.com/docker/cli/cli/config/config.go ${B}/pkg/mod/github.com/docker/cli@v20.10.3-0.20220309205733-2b52f62e9627+incompatible/cli/config/config.go
	${GO} build ${GOBUILDFLAGS} -o ${B}/cli-plugins/bin/docker-compose ./cmd
}

go_do_install:append() {
	install -d ${D}${libdir}/docker/cli-plugins
	install -m 755 ${B}/cli-plugins/bin/docker-compose ${D}${libdir}/docker/cli-plugins
}

FILES:${PN} += "${libdir}/docker/cli-plugins"

RDEPENDS:${PN} += "docker"
