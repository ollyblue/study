t = "000200b4f3d3af030000000000000009000000"

def decode_value(v):
	v_len = len(v)
	v_list = []
	for i in xrange(0, v_len, 2):
		v_list.append(v[i:i+2])
	v_list.reverse()
	return int("".join(v_list), 16)

def encode_value(v, v_len):
	v_list = []
	v_len *= 2
	fmt = "0%d" % v_len
	fmt = "%" + fmt + "X"
	code = fmt % v

	for i in xrange(0, v_len, 2):
		v_list.append(code[i:i+2])

	v_list.reverse()

	return "".join(v_list)
	#print "".join(v_list)


def decode_redis_key(t):
	key_type = t[0:2]
	biz_type = t[2:6]
	key_16 = t[6:22]
	redis_svr_id = t[22:30]
	sub_biz_type = t[30:38]

	i_key_type = decode_value(key_type)
	i_biz_type = decode_value(biz_type)
	i_key_16 = decode_value(key_16)
	i_redis_svr_id = decode_value(redis_svr_id)
	i_sub_biz_type = decode_value(sub_biz_type)
	print("key_type:\t0x%02X\nbiz_type:\t0x%04X\nkey:\t\t%d\nreids_svr:\t%d\nsub_biz_type:\t0x%08X\n" % \
			( i_key_type, i_biz_type, i_key_16, i_redis_svr_id, i_sub_biz_type))

def encode_redis_key(key, key_len, biz_type, sub_biz_type, key_type = 0, redis_svr_id = 0):
	en_key = encode_value(key, key_len)
	en_key_type = encode_value(key_type, 1)
	en_biz_type = encode_value(biz_type, 2)
	en_sub_biz_type = encode_value(sub_biz_type, 4)
	en_reids_svr_id = encode_value(redis_svr_id, 4)
	value = str(en_key_type) + str(en_biz_type) + str(en_key) + str(en_reids_svr_id) + str(en_sub_biz_type)
	value = value.lower()
	print value
	return value

def get_uid_key(uid):
	return encode_redis_key(uid, 8, 0x2, 0x9)

def get_basic_info_key(uid):
	return encode_redis_key(uid, 8, 0x2, 0x10)

def get_user_info_battery(uid):
	return encode_redis_key(uid, 8, 0x2, 0x10)

def get_user_info_login_time(uid):
	return encode_redis_key(uid, 8, 0x4, 0x12)


decode_redis_key(t)
encode_value(15834805172,8)
print t
encode_redis_key(15834805172, 8, 0x2, 0x9)

print "uid",get_uid_key(15834805172)

print "hget",get_basic_info_key(2000000272)

s = get_user_info_login_time(13556885667)
print s
