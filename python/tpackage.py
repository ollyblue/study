
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


if __name__ == "__main__":
	t = tpack()
	#t.add_char("A")
	#t.add_schar(127)
	#t.add_schar(15)
	#t.add_short(32767)
	#t.add_longlong(12345678)
	s = "test"

	t.add_ushort(0x11FF)
	t.add_ulonglong(0x11FF)
	t.add_wstr(len(s), s)
	print("len:%d" % t.get_len())
	#t.printf()
	t.printhex()



