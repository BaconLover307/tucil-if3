#!/usr/bin/python2.7
# Penggunaan: python hex2raw.py <token>
# 			  akan mengubah hex di input.txt
#			  menjadi raw byte dan mencetaknya ke stdout

import sys
import binascii

if (len(sys.argv) > 1):
	if (len(sys.argv[1]) == 10):
		print sys.argv[1]

with open('input.txt', 'rb') as fin:
	raw = fin.readlines()[0].strip()
	raw = raw.replace(' ', '')
	payload = binascii.unhexlify(raw)

print payload