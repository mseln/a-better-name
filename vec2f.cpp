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



#include <math.h>

#include "vec2f.h"

using namespace std;

Vec2f::Vec2f() {
	
}

Vec2f::Vec2f(float x, float y) {
	v[0] = x;
	v[1] = y;
}

float &Vec2f::operator[](int index) {
	return v[index];
}

float Vec2f::operator[](int index) const {
	return v[index];
}

Vec2f Vec2f::operator*(float scale) const {
	return Vec2f(v[0] * scale, v[1] * scale);
}

Vec2f Vec2f::operator/(float scale) const {
	return Vec2f(v[0] / scale, v[1] / scale);
}

Vec2f Vec2f::operator+(const Vec2f &other) const {
	return Vec2f(v[0] + other.v[0], v[1] + other.v[1]);
}

Vec2f Vec2f::operator-(const Vec2f &other) const {
	return Vec2f(v[0] - other.v[0], v[1] - other.v[1]);
}

Vec2f Vec2f::operator-() const {
	return Vec2f(-v[0], -v[1]);
}

const Vec2f &Vec2f::operator*=(float scale) {
	v[0] *= scale;
	v[1] *= scale;
	return *this;
}

const Vec2f &Vec2f::operator/=(float scale) {
	v[0] /= scale;
	v[1] /= scale;
	return *this;
}

const Vec2f &Vec2f::operator+=(const Vec2f &other) {
	v[0] += other.v[0];
	v[1] += other.v[1];
	return *this;
}

const Vec2f &Vec2f::operator-=(const Vec2f &other) {
	v[0] -= other.v[0];
	v[1] -= other.v[1];
	return *this;
}

float Vec2f::magnitude() const {
	return sqrt(v[0] * v[0] + v[1] * v[1]);
}

float Vec2f::magnitudeSquared() const {
	return v[0] * v[0] + v[1] * v[1];
}

Vec2f Vec2f::normalize() const {
	float m = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	return Vec2f(v[0] / m, v[1] / m);
}

float Vec2f::dot(const Vec2f &other) const {
	return v[0] * other.v[0] + v[1] * other.v[1];
}

float * Vec2f::toFloat(){
	float *temp = v;
	return temp;
}

float Vec2f::set(int index, float value){
	v[index] = value;
}

Vec2f operator*(float scale, const Vec2f &v) {
	return v * scale;
}

ostream &operator<<(ostream &output, const Vec2f &v) {
	cout << '(' << v[0] << ", " << v[1] << ')';
	return output;
}