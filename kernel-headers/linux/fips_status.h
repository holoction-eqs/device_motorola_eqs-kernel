/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _FIPS_STATUS__H
#define _FIPS_STATUS__H
#include <linux/types.h>
#include <linux/ioctl.h>
enum fips_status {
  FIPS140_STATUS_NA = 0,
  FIPS140_STATUS_PASS_CRYPTO = 1,
  FIPS140_STATUS_QCRYPTO_ALLOWED = 2,
  FIPS140_STATUS_PASS = 3,
  FIPS140_STATUS_FAIL = 0xFF
};
#endif
