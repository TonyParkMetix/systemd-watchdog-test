DESCRIPTION = "Systemd Watchdog Test"
HOMEPAGE = "https://github.com/TonyParkMetix/systemd-watchdog-test"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE.MIT;md5=544799d0b492f119fa04641d1b8868ed"

inherit cmake pkgconfig

SRCREV = "${AUTOREV}"
PV = "0.1+gitr${SRCPV}"
PR = "r4"

DEPENDS = " systemd "
RDEPENDS_${PN} = " systemd "


SRC_URI = "git://github.com/TonyParkMetix/systemd-watchdog-test;protocol=git;branch=master"

S = "${WORKDIR}/git"

FILES_${PN} += "/lib/systemd/system/"



