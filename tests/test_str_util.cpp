#include <gtest/gtest.h>
#include "str_util.h"

TEST(StrUtil, Strcpyz)
{
	char buf[8];
	strcpyz(buf, "test");
	EXPECT_STREQ("test", buf);
}
