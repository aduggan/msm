#ifndef _RMI_COMPAT_H_
#define _RMI_COMPAT_H_

#include <linux/of.h>

struct input_mt_pos {
	s16 x, y;
};

#define INPUT_MT_POINTER		0x0001
#define INPUT_MT_DIRECT         	0x0002
#define INPUT_MT_TRACK         		0x0008

#define INPUT_PROP_TOPBUTTONPAD         0x04

static inline int of_property_read_u16(const struct device_node *np,
						const char *propname,
						u16 *out_value)
{
	u64 out = 0;
	int ret;

	ret = of_property_read_u64(np, propname, &out);
	*out_value = (u16)out;

	return ret;
}

static inline int of_property_read_u8(const struct device_node *np,
						const char *propname,
						u8 *out_value)
{
	u64 out = 0;
	int ret;

	ret = of_property_read_u64(np, propname, &out);
	*out_value = (u8)out;

	return ret;
}

/* this will leak since the new string is never freed */
#define devm_kasprintf(dev, gfp, fmt, ...) kasprintf(gfp, fmt, __VA_ARGS__)
#define devm_input_allocate_device(dev) input_allocate_device()
#define input_mt_init_slots(input, fingers, input_flags) input_mt_init_slots(input, fingers)

static inline void input_mt_sync_frame(struct input_dev *dev)
{
}

static inline int input_mt_assign_slots(struct input_dev *dev, int *slots,
				const struct input_mt_pos *pos, int num_pos,
				int dmax)
{
	return 0;
}
#endif
