#include <gtest/gtest.h>
#include "str_util.h"
#include "bootcore_utils.h"

TEST(BootcoreUtils, NameMatch)
{
	// Should match core with date suffix
	EXPECT_TRUE(preciseMatchOrGenericCoreName("PSX", "PSX_20250629.rbf"));

	// Should not match missing date
	EXPECT_FALSE(preciseMatchOrGenericCoreName("PSX", "PSX.rbf"));

	// Should not match wrong prefix
	EXPECT_FALSE(preciseMatchOrGenericCoreName("SNES", "PSX_20250629.rbf"));

	// Should not match wrong extension
	EXPECT_FALSE(preciseMatchOrGenericCoreName("SNES", "SNES_20250629.ps2"));

	// Should match precise core files
	EXPECT_TRUE(preciseMatchOrGenericCoreName("PSX_20250629.rbf", "PSX_20250629.rbf"));

	// Should not match core files with different versions
	EXPECT_FALSE(preciseMatchOrGenericCoreName("PSX_20250629.rbf", "PSX_20190629.rbf"));
}
