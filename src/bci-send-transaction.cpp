/**
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
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
#include <sx/command/bci-send-transaction.hpp>

#include <iostream>
#include <sx/utility/utility.hpp>

using namespace sx;
using namespace sx::extension;

console_result bci_send_transaction::invoke(std::istream& input,
    std::ostream& output, std::ostream& cerr)
{
    // Bound parameters.
    auto filename = get_file_option();

    cerr << SX_BCI_SEND_TRANSACTION_NOT_IMPLEMENTED << std::endl;
    return console_result::failure;
}

//#!/usr/bin/python
//
//import urllib, urllib2, sys, urllib2, random
//
//if len(sys.argv) < 2: 
//    print "Need TX argument"
//    sys.exit(-1)
//
//if sys.argv[1] == "-":
//    txdata = sys.stdin.read().strip()
//else:
//    txdata = open(sys.argv[1]).read().strip()
//
//opener = urllib2.build_opener()
//opener.addheaders = [('User-agent', 'Mozilla/5.0'+str(random.randrange(1000000)))]
//
//url = 'http://blockchain.info/pushtx'
//form_data = {'tx': txdata }
//params = urllib.urlencode(form_data)
//try:
//    response = opener.open(url, params)
//    data = response.read()
//except Exception, e:
//    data = e.read().strip()
//
//if len(data) < 500:
//    print data
//    sys.exit(0)
//else:
//    sys.stderr.write(data)
//    sys.exit(-1)