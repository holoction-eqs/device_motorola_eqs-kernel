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
#ifndef _UAPI_QCOTA_H
#define _UAPI_QCOTA_H
#include <linux/types.h>
#include <linux/ioctl.h>
#define QCE_OTA_MAX_BEARER 31
#define OTA_KEY_SIZE 16
enum qce_ota_dir_enum {
  QCE_OTA_DIR_UPLINK = 0,
  QCE_OTA_DIR_DOWNLINK = 1,
  QCE_OTA_DIR_LAST
};
enum qce_ota_algo_enum {
  QCE_OTA_ALGO_KASUMI = 0,
  QCE_OTA_ALGO_SNOW3G = 1,
  QCE_OTA_ALGO_LAST
};
struct qce_f8_req {
  __u8 * data_in;
  __u8 * data_out;
  __u16 data_len;
  __u32 count_c;
  __u8 bearer;
  __u8 ckey[OTA_KEY_SIZE];
  enum qce_ota_dir_enum direction;
  enum qce_ota_algo_enum algorithm;
  int current_req_info;
};
struct qce_f8_multi_pkt_req {
  __u16 num_pkt;
  __u16 cipher_start;
  __u16 cipher_size;
  struct qce_f8_req qce_f8_req;
};
#define MAX_NUM_V_MULTI_PKT 20
struct cipher_iov {
  unsigned char * addr;
  unsigned short size;
};
struct qce_f8_variable_multi_pkt_req {
  unsigned short num_pkt;
  struct cipher_iov cipher_iov[MAX_NUM_V_MULTI_PKT];
  struct qce_f8_req qce_f8_req;
};
struct qce_f9_req {
  __u8 * message;
  __u16 msize;
  __u8 last_bits;
  __u32 mac_i;
  __u32 fresh;
  __u32 count_i;
  enum qce_ota_dir_enum direction;
  __u8 ikey[OTA_KEY_SIZE];
  enum qce_ota_algo_enum algorithm;
  int current_req_info;
};
#define QCOTA_IOC_MAGIC 0x85
#define QCOTA_F8_REQ _IOWR(QCOTA_IOC_MAGIC, 1, struct qce_f8_req)
#define QCOTA_F8_MPKT_REQ _IOWR(QCOTA_IOC_MAGIC, 2, struct qce_f8_multi_pkt_req)
#define QCOTA_F9_REQ _IOWR(QCOTA_IOC_MAGIC, 3, struct qce_f9_req)
#define QCOTA_F8_V_MPKT_REQ _IOWR(QCOTA_IOC_MAGIC, 4, struct qce_f8_variable_multi_pkt_req)
#endif
