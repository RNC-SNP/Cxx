// ./ card > card.jpg
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct v{
	float x, y, z;
    
	v(){

	}
    
	v(float a, float b, float c){
		x = a;
        y = b;
        z = c;
	}
    
	v operator!() {
		return *this * (1 / sqrt(*this % *this));
	}
    
    v operator^(v r){
        return v(y * r.z - z * r.y, z * r.x - x * r.z, x * r.y - y * r.x);
    }
    
    v operator+(v r){
        return v(x + r.x, y + r.y, z + r.z);
    }
    
    v operator*(float r){
        return v(x * r, y * r, z * r);
    }
    
    float operator%(v r){
        return x * r.x + y * r.y + z * r.z;
    }
};

int G[] = {247570, 280596, 280600, 249748, 18578, 18577, 231184, 16, 16};

float R(){
	return (float)rand() / RAND_MAX;
}

int T(v o, v d, float &t, v &n){
	t = 1e9;
	int m = 0;
	float p = -o.z / d.z;
	if(.01 < p){
		t = p, n = v(0, 0, 1), m = 1;
	}
	for(int k = 19; k--;){
		for(int j = 9; j--;){
			if(G[j] & 1 << k){
				v p = o + v(-k, 0, -j - 4);
				float b = p % d, c = p % p - 1, q = b * b - c;
				if(q > 0){
					float s = -b - sqrt(q);
					if(s < t && s >.01){
						t = s, n =!(p + d * t), m = 2;
					}
				}
			}
		}
	}
	return m;
}

v S(v o, v d){
	float t;
	v n;
	int m = T(o, d, t, n);
	if(!m){
		return v(.7, .6 ,1) * pow(1 - d.z, 4);
	}
	v h = o + d * t, l = !(v(9 + R(), 9 + R(), 16) + h * - 1), r = d + n * (n % d * -2);
	float b = l % n;
	if(b < 0 || T(h, l, t, n)){
		b = 0;
	}
	float p = pow(l % r * (b > 0), 99);
	if(m & 1){
		h = h * .2;
		return ((int)(ceil(h.x) + ceil(h.y)) & 1 ? v(3, 1, 1) : v(3, 3, 3)) * (b * .2 + .1);
	}
	return v(p, p, p) + S(h, r) * .5;
}

int main(){
	printf("P6 512 512 255 ");
	v g = !v(-6, -16, 0), a = !(v(0, 0, 1) ^ g) * .002, b = !(g ^ a) * .002, c = (a + b) * -256 + g;
	for(int y = 512; y--;){
		for(int x = 512; x--;){
			v p(13, 13, 13);
			for(int r = 64; r--;){
				v t = a * (R() - .5) * 99 + b * (R() - .5) * 99;
				p = S(v(17, 16, 8) + t, !(t * -1 + (a * (R() + x) + b * (y + R()) + c) * 16)) * 3.5 + p;
			}
			printf("%c%c%c", (int)p.x, (int)p.y, (int)p.z);
		}
	}
}
