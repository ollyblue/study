
import struct
import binascii


class tpack:
	def __init__(self, endian = True):
		self.s = list()
		self.len = 0
		'''little-endian or big-endian when, endian is True => big-endian'''
		self.endian = endian

	def get_len(self):
		return self.len

	def add_char(self, c):
		pack =  ''
		if self.endian == True:
			pack = struct.pack('!c',c)
		else:
			pakc = struct.pack('c',c)
		self.s.extend( list(pack))
		self.len += 1

	def add_schar(self, c):
		pack =  ''
		fmt = "%sb" % ( self.endian == True and "!" or "")
		print(fmt)
		pakc = struct.pack(fmt,c)
		self.s.extend( list(pack))
		self.len += 1

	def add_uchar(self, c):
		pack =  ''
		if self.endian == True:
			pack = struct.pack('!B',c)
		else:
			pakc = struct.pack('B',c)
		self.s.extend( list(pack))
		self.len += 1
	def add_short(self, v):
		pack = ''
		if self.endian == True:
			pack = struct.pack('!h', v)
		else:
			pack = struct.pack('h', v)
		self.s.extend(list(pack))
		self.len += 2

	def add_ushort(self, v):
		pass

	def add_int(self, v):
		pass

	def add_uint(self, v):
		pass

	def add_long(self, v):
		pass

	def add_ulong(self, v):
		pass

	def add_longlong(self, v):
		pack = ''
		pack = struct.pack('q', v)
		self.s.extend(list(pack))
		self.len += 8

	def add_ulonglong(self, v):
		pass

	def add_float(self, v):
		pass

	def add_double(self, v):
		pass

	def add_cstr(self, len, s):
		pass

	def add_wstr(self, len, s):
		pass
		
	def printf(self):
		print(self.s)

	def printhex(self):
		self.len = len(self.s)
		tlist = list(self.s)
		#print(dir(self.s))
	#	for x in self.s:
			#print(dir(x))
	#		print("%s" % x)
		print("begin ascii")
		t_hex = binascii.b2a_hex(''.join(self.s))
		print("len t_hex:%d" % len(t_hex))
		print(binascii.b2a_hex(''.join(self.s)))
		print("end ascii")
		for i in xrange(0,self.len):
			print("i:%d v:%s" % (i, tlist[i]))


if __name__ == "__main__":
	t = tpack()
	t.add_char("A")
	#t.add_schar(127)
	#t.add_schar(15)
	t.add_short(32767)
	t.add_longlong(12345678)
	print("len:%d" % t.get_len())
	#t.printf()
	t.printhex()



