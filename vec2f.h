/* Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef VEC2F_H_INCLUDED
#define VEC2F_H_INCLUDED

#include <iostream>

class Vec2f {
	private:
		float v[2];
	public:
		Vec2f();
		Vec2f(float x, float y);
		
		float &operator[](int index);
		float operator[](int index) const;
		
		Vec2f operator*(float scale) const;
		Vec2f operator/(float scale) const;
		Vec2f operator+(const Vec2f &other) const;
		Vec2f operator-(const Vec2f &other) const;
		Vec2f operator-() const;
		bool  operator==(const Vec2f &other) const;
	
		
		const Vec2f &operator*=(float scale);
		const Vec2f &operator/=(float scale);
		const Vec2f &operator+=(const Vec2f &other);
		const Vec2f &operator-=(const Vec2f &other);
	
		float magnitude() const;
		float magnitudeSquared() const;
		Vec2f normalize() const;
		float dot(const Vec2f &other) const;
	
		float * toFloat();
		float set(int index, float value);
};

Vec2f operator*(float scale, const Vec2f &v);
std::ostream &operator<<(std::ostream &output, const Vec2f &v);

#endif
