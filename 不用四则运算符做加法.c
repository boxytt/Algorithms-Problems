// 不用＋、－、×、÷做加法

int AddWithoutArithmetic(int num1, int num2) {
        if (num2 == 0) {
            return num1;
        }
 
        int sum = num1 ^ num2;
        int carry = (num1 & num2) << 1;
 
        return AddWithoutArithmetic(sum, carry);
}