int UTF8toUTF16(int c)
{
	signed char *t=(signed char*)&c;
	int ret=*t &(0x0f | (~(*t>>1) &0x1f) | ~(*t>>7));
	int i;
	assert ((*t & 0xc0) != 0x80);
	for (i=1;i<3;i++) {
		if ((t[i] & 0xc0)!=0x80) {
			break;
		}
		ret=ret<<6 | (t[i] & 0x3f);
	}
	return ret;
}