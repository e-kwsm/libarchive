/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2025 Eisuke Kawashima
 * All rights reserved.
 */
#include "test.h"

DEFINE_TEST(test_expand_bz2)
{
	const char *reffile = "test_expand.br";
	int f;

	extract_reference_file(reffile);
	f = systemf("%s %s >test.out 2>test.err", testprog, reffile);
	if (f == 0 || canBzip2()) {
		assertEqualInt(0, f);
		assertTextFileContents("contents of test_expand.br.\n", "test.out");
		assertEmptyFile("test.err");
	} else {
		skipping("It seems brotli is not supported on this platform");
	}
}
