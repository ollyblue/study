
import struct
import binascii


class tpack:
	def __init__(self, endian = True):
		self.s = list()
		self.len = 0
		'''little-endian or big-endian when endian is True => big-endian'''
		self.endian = endian

	def get_len(self):
		return self.len

	def add_char(self, c):
		fmt = "%sb" % ( self.endian == True and "!" or "")
		pack = struct.pack(fmt, c)
		self.s.extend(pack)
		self.len += 1

	def add_schar(self, c):
		fmt = "%sb" % ( self.endian == True and "!" or "")
		pack = struct.pack(fmt, c)
		self.s.extend(pack)
		self.len += 1

	def add_uchar(self, c):
		fmt = "%sB" % ( self.endian == True and "!" or "")
		pack = struct.pack(fmt, c)
		self.s.extend(pack)
		self.len += 1

	def add_short(self, v):
		fmt = "%sh" % (self.endian == True and "!" or "")
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 2

	def add_ushort(self, v):
		fmt = "%sH" % ( self.endian == True and "!" or "" )
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 2

	def add_int(self, v):
		fmt = "%si" % ( self.endian == True and "!" or "" )
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 4


	def add_uint(self, v):
		fmt = "%sI" % ( self.endian == True and "!" or "" )
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 4

	def add_long(self, v):
		fmt = "%sl" % ( self.endian == True and "!" or "" )
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 4

	def add_ulong(self, v):
		fmt = "%sL" % ( self.endian == True and "!" or "" )
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 4

	def add_longlong(self, v):
		fmt = "%sq" % ( self.endian == True and "!" or "" )
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 8

	def add_ulonglong(self, v):
		fmt = "%sQ" % ( self.endian == True and "!" or "" )
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 8

	def add_float(self, v):
		fmt = "%sf" % ( self.endian == True and "!" or "" )
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 8

	def add_double(self, v):
		fmt = "%sF" % ( self.endian == True and "!" or "" )
		pack = struct.pack(fmt, v)
		self.s.extend(pack)
		self.len += 8

	def add_cstr(self, len, s):
		fmt = "%sB%ds" % ( self.endian == True and "!" or "", len )
		pack = struct.pack(fmt, len, s)
		self.s.extend(pack)
		self.len += 1
		self.len += len

	def add_wstr(self, len, s):
		fmt = "%sH%ds" % ( self.endian == True and "!" or "", len )
		pack = struct.pack(fmt, len, s)
		self.s.extend(pack)
		self.len += 2
		self.len += len

	def add_dwstr(self, len, s):
		fmt = "%sI%ds" % ( self.endian == True and "!" or "", len )
		pack = struct.pack(fmt, len, s)
		self.s.extend(pack)
		self.len += 4
		self.len += len
	def add_str_by_len(self, s, len):
		fmt = "%s%ds" % (self.endian == True and "!" or "", len)
		pack = struct.pack(fmt, s)
		self.s.extend(pack)
		self.len += len
	
	def get_pack(self):
		return self.s
		
	def printf(self):
		print(self.s)

	def printhex(self):
		print "begin ascii"
		t_hex = binascii.b2a_hex(''.join(self.s))
		len_hex = len(t_hex)
		hex_line = 0
		hex_num = 0

		for x in xrange(0, len_hex, 4):
			if( x == 0 or x % 32 == 0 ):
				print ""
				print "%06X\t" % (hex_line/8),
			print t_hex[x:x+4],
			hex_line += 1

		'''
			if( len_hex % 2 == 0 and len_hex == 0 ):
				print "%s " %t_hex[x:x+2],
				len_hex += 1
			else:
				print "%s" %t_hex[x:x+2],
				len_hex += 1
		'''

		print("\nlen t_hex:%d" % len(t_hex))
		print(binascii.b2a_hex(''.join(self.s)))
		print("end ascii")

class tunpack:
	def __init__(self, s, s_len, endian = True):
		self.s = s
		self.s_len = s_len
		self.endian = endian
		self.done_len  = 0
	
	def get_char(self):
		if self.s_len - self.done_len >= 1:
			fmt = "%sb" % ( self.endian == True and "!" or "" )
			v, = struct.unpack_from(fmt, self.s[0], 0)
			self.done_len += 1
			return v
		raise IndexError('out of range')

	def get_uchar(self):
		if self.s_len - self.done_len >= 1:
			fmt = "%sB" % ( self.endian == True and "!" or "" )
			v, = struct.unpack_from(fmt, self.s[0], 0)
			self.done_len += 1
			return v
		raise IndexError('out of range')

	def get_short(self):
		if self.s_len - self.done_len >= 2:
			fmt = "%sh" % ( self.endian == True and "!" or "" )
			s = "".join(self.s[self.done_len:self.done_len+2])
			v, = struct.unpack(fmt,s)
			self.done_len += 2
			return v
		raise IndexError('out of range')

	def get_ushort(self):
		if self.s_len - self.done_len >= 2:
			fmt = "%sH" % ( self.endian == True and "!" or "" )
			s = "".join(self.s[self.done_len:self.done_len+2])
			v, = struct.unpack(fmt,s)
			self.done_len += 2
			return v
		raise IndexError('out of range')

	def get_int(self):
		if self.s_len - self.done_len >= 2:
			fmt = "%si" % ( self.endian == True and "!" or "" )
			s = "".join(self.s[self.done_len:self.done_len+4])
			v, = struct.unpack(fmt,s)
			self.done_len += 4
			return v
		raise IndexError('out of range')

	def get_uint(self):
		if self.s_len - self.done_len >= 2:
			fmt = "%sI" % ( self.endian == True and "!" or "" )
			s = "".join(self.s[self.done_len:self.done_len+4])
			v, = struct.unpack(fmt,s)
			self.done_len += 4
			return v
		raise IndexError('out of range')

	def get_longlong(self):
		if self.s_len - self.done_len >= 8:
			fmt = "%sq" % ( self.endian == True and "!" or "" )
			s = "".join(self.s[self.done_len:self.done_len+8])
			v, = struct.unpack(fmt, s)
			self.done_len += 8
			return v
		raise IndexError('out of range')

	def get_ulonglong(self):
		if self.s_len - self.done_len >= 8:
			fmt = "%sQ" % ( self.endian == True and "!" or "" )
			s = "".join(self.s[self.done_len:self.done_len+8])
			v, = struct.unpack(fmt, s)
			self.done_len += 8
			return v
		raise IndexError('out of range')

	def get_float(self):
		if self.s_len - self.done_len >= 8:
			fmt = "%sf" % ( self.endian == True and "!" or "" )
			s = "".join(self.s[self.done_len:self.done_len+4])
			v, = struct.unpack(fmt, s)
			self.done_len += 4
			return v
		raise IndexError('out of range')

	def get_double(self):
		if self.s_len - self.done_len >= 8:
			fmt = "%sF" % ( self.endian == True and "!" or "" )
			s = "".join(self.s[self.done_len:self.done_len+8])
			v, = struct.unpack(fmt, s)
			self.done_len += 8
			return v
		raise IndexError('out of range')

	''' string not include size'''
	def get_str(self,size):
		if self.s_len - self.done_len >= size:
			fmt = "%s%ds" % ( self.endian == True and "!" or "", size )
			s = "".join(self.s[self.done_len:self.done_len+size])
			v, = struct.unpack(fmt, s)
			self.done_len += size
			return v
		raise IndexError('out of range')

	'''string include one byte size'''
	def get_cstr(self):
		if self.s_len - self.done_len >= 1:
			fmt = "%sB" % ( self.endian == True and "!" or "", size )
			size = 1
			s = "".join(self.s[self.done_len:self.done_len+size])
			str_len, = struct.unpack(fmt, s)
			if self.s_len - self.done_len >= str_len:
				fmt = "%s%ds" % ( self.endian == True and "!" or "", size, str_len )
				self.done_len += size
				size = str_len
				s = "".join(self.s[self.done_len:self.done_len+size])
				str, = struct.unpack(fmt, s)
				return str_len,str
		raise IndexError('out of range')

	'''string include tow byte size'''
	def get_wstr(self):
		if self.s_len - self.done_len >= 2:
			fmt = "%sB" % ( self.endian == True and "!" or "", size )
			size = 2
			s = "".join(self.s[self.done_len:self.done_len+size])
			str_len, = struct.unpack(fmt, s)
			if self.s_len - self.done_len >= str_len:
				fmt = "%s%ds" % ( self.endian == True and "!" or "", size, str_len )
				self.done_len += size
				size = str_len
				s = "".join(self.s[self.done_len:self.done_len+size])
				str, = struct.unpack(fmt, s)
				return str_len,str
		raise IndexError('out of range')

if __name__ == "__main__":
	t = tpack()
	#t.add_char("A")
	#t.add_schar(127)
	#t.add_schar(15)
	#t.add_short(32767)
	#t.add_longlong(12345678)
	s = "test"

	t.add_char(1)
	t.add_ushort(2335)
	t.add_ulonglong(1112234)
	str = "test"
	t.add_str_by_len(str, len(str))
	#t.add_wstr(len(s), s)
	print("len:%d" % t.get_len())
	#t.printf()
	t.printhex()

	ss = t.get_pack()
	unt = tunpack(ss, len(ss) )
	c = unt.get_char()
	us = unt.get_ushort()
	uv = unt.get_ulonglong()
	vstr = unt.get_str(len(str))
	print c,us,uv,vstr



