/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "nlmon.h"

static int netdev_nlmon_verify(NetDev *netdev, const char *filename) {
        assert(netdev);
        assert(filename);

        if (netdev->mac) {
                log_netdev_warning(netdev, "%s: MACAddress= is not supported. Ignoring", filename);
                netdev->mac = mfree(netdev->mac);
        }

        return 0;
}

const NetDevVTable nlmon_vtable = {
        .object_size = sizeof(NLMon),
        .sections = NETDEV_COMMON_SECTIONS,
        .create_type = NETDEV_CREATE_INDEPENDENT,
        .config_verify = netdev_nlmon_verify,
};
