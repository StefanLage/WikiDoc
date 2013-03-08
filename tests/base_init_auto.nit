# This file is part of NIT ( http://www.nitlanguage.org ).
#
# Copyright 2009 Jean Privat <jean@pryen.org>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import kernel

class A
	readable var _x: Int #alt1#
	#alt1#readable var _x: Int = 2
	readable var _y: Int = -2 #alt2#
	#alt2#readable var _y: Int
	#alt3#init (xx: Int) do _x = xx
	#alt4#init foo(xx: Int) do _x = xx
	fun work
	do
		_x.output
		_y.output
	end
end

var a: A
a = new A(1)#alt1##alt2##alt3##alt4#
#alt1#a = new A
#alt2#a = new A(3, -3)
#alt3#a = new A(4)
#alt4#a = new A.foo(5)
a.work


