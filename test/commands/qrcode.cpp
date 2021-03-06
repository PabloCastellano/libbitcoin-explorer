/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-explorer.
 *
 * libbitcoin-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "command.hpp"

BX_USING_NAMESPACES()

BOOST_AUTO_TEST_SUITE(stub)
BOOST_AUTO_TEST_SUITE(qrcode__invoke)

#if defined WITH_QRENCODE && defined WITH_PNG
BOOST_AUTO_TEST_CASE(qrcode__invoke__always__failure_error)
{
    BX_DECLARE_COMMAND(qrcode);
    command.set_size_option(0);
    command.set_image_option(true);
    BX_REQUIRE_FAILURE(command.invoke(output, error));
}

BOOST_AUTO_TEST_CASE(qrcode__invoke__size_one__success)
{
    BX_DECLARE_COMMAND(qrcode);

    unsigned char test_qrout_png[] = {
        0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
        0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x21,
        0x01, 0x03, 0x00, 0x00, 0x00, 0x6d, 0x2a, 0x50, 0x2c, 0x00, 0x00, 0x00,
        0x06, 0x50, 0x4c, 0x54, 0x45, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xa5,
        0xd9, 0x9f, 0xdd, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0xff,
        0xff, 0xc8, 0xb5, 0xdf, 0xc7, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59,
        0x73, 0x00, 0x00, 0x0a, 0xf8, 0x00, 0x00, 0x0a, 0xf8, 0x01, 0x66, 0x26,
        0x3c, 0xfd, 0x00, 0x00, 0x00, 0xb2, 0x49, 0x44, 0x41, 0x54, 0x08, 0x99,
        0x63, 0xf8, 0x0f, 0x02, 0x0c, 0x10, 0xf2, 0x40, 0xce, 0x61, 0xc6, 0xff,
        0x0c, 0xf7, 0x0b, 0x85, 0x6b, 0xff, 0x33, 0x5c, 0x74, 0x89, 0x77, 0x05,
        0x92, 0x49, 0xc6, 0x20, 0xb2, 0xbc, 0x1c, 0x48, 0xde, 0xcf, 0x7b, 0x0c,
        0x14, 0x3f, 0x10, 0x1a, 0x0a, 0x54, 0xf3, 0xff, 0x88, 0x3f, 0x50, 0xfd,
        0x11, 0x61, 0xb9, 0xf2, 0xff, 0x0c, 0x1f, 0x2f, 0x1b, 0xa4, 0xfe, 0x67,
        0x38, 0x96, 0xf7, 0xe5, 0xea, 0x7f, 0x86, 0x1f, 0xbf, 0xcf, 0x02, 0xc5,
        0xcf, 0xc5, 0x9e, 0xd4, 0xfc, 0xcf, 0xf0, 0xf3, 0xc6, 0x59, 0xdd, 0xff,
        0x0c, 0x0f, 0x0d, 0xd3, 0x22, 0xff, 0x33, 0xdc, 0xb8, 0xe2, 0x3c, 0xf3,
        0x3f, 0xc3, 0x4d, 0xe3, 0xd8, 0xd2, 0xff, 0x0c, 0xef, 0x5e, 0xbb, 0xe6,
        0x02, 0x45, 0xe4, 0xbe, 0xf6, 0xfe, 0x67, 0x78, 0xfe, 0xfa, 0x75, 0xff,
        0x7f, 0x86, 0x7b, 0xa6, 0x3d, 0xbc, 0x40, 0x33, 0x6f, 0x4c, 0xbd, 0x0b,
        0x34, 0xdf, 0xb1, 0x30, 0x14, 0x68, 0x97, 0x8f, 0xee, 0x4d, 0xa0, 0xbd,
        0xc1, 0x31, 0xac, 0x40, 0xb2, 0xd8, 0xbd, 0x13, 0x48, 0xfa, 0xbd, 0x9d,
        0x0a, 0x14, 0x0f, 0x5e, 0xbc, 0x1b, 0xa8, 0x26, 0xb6, 0x23, 0x13, 0xe6,
        0x66, 0x30, 0x09, 0x00, 0xec, 0x6d, 0x72, 0xe5, 0xc2, 0xa9, 0xe2, 0x5b,
        0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
    };
    unsigned int test_qrout_png_len = 288;

    command.set_size_option(1);
    command.set_image_option(true);
    command.set_payment_address_argument(libbitcoin::wallet::payment_address(
        "12u8rC4Pxih4m59eApanRDodXcPxWiaKgg"));

    BX_REQUIRE_OKAY(command.invoke(output, error));

    //Read in the generated qrcode png output stream and compare to
    // known good output stored above
    istream_reader in(output);
    data_chunk data = in.read_data_to_eof();

    BOOST_REQUIRE(data.size() == test_qrout_png_len);
    BOOST_REQUIRE(std::memcmp(test_qrout_png, data.data(),
        test_qrout_png_len) == 0);
}

#else
BOOST_AUTO_TEST_CASE(qrcode__invoke__always__failure_error)
{
    BX_DECLARE_COMMAND(qrcode);
    BX_REQUIRE_FAILURE(command.invoke(output, error));
    BX_REQUIRE_ERROR(BX_QRCODE_REQUIRES_QRENCODE "\n");
}
#endif

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
