/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  for test protobuf
 *
 *        Version:  1.0
 *        Created:  06/16/2014 09:58:04 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  bluezheng (bluezheng@tencent.com)
 *        Company:  Tencent
 *
 * =====================================================================================
 */

#include "addr.pb.h"

#include <stdio.h>

static void PHex(const char *pSrc, size_t len);


int main(int argc, const char *argv[])
{
	Persion objP;

	objP.set_name("blue");
	objP.set_id(10);
	objP.set_email("test@tencent.com");

	Persion_PhoneNumber *pPhoneNumber = objP.add_phone();

	pPhoneNumber->set_phonenum("12345");
	pPhoneNumber->set_type(Persion_PhoneType_WORK);


	std::string strSerializeData;

	objP.SerializeToString(&strSerializeData);

	std::string strDebugStr = objP.DebugString();

	printf("serialize data:%s\n", strSerializeData.c_str());
	printf("\n");
	for(size_t i = 0; i < strSerializeData.size(); ++i)
	{
		if( i % 16 == 0 && i != 0 )
		{
			printf("\n");
		}
		printf("%02x ", strSerializeData[i]);
	}
	printf("\n");
	printf("debug str:%s\n", strDebugStr.c_str());

	PHex(strSerializeData.c_str(), strSerializeData.size() );

	return 0;
}

static void PHex(const char *pSrc, size_t len)
{
	size_t l = 0;
	printf("0x%05lx\t", l);
	for( l = 0; l < len; ++l)
	{
		if( l % 16 == 0 && l != 0 )
		{
			printf("\n");
			printf("0x%05lx\t", l);
		}
		printf("%02x", pSrc[l]);
		++l;
		if( l < len )
		{
			printf("%02x ", pSrc[l]);
		}
	}
	printf("\n");
}
