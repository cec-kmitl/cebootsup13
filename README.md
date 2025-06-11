<h1 align="center">America's test kitchen</h1>

<div align="center">
  <img src="" width="40" style="border-radius: 50%; vertical-align: middle;" />
  <b>pooooooooooooooooooweeh</b>
</div>

---

## 🆔 Problem ID: 143

### 📋 Description

แปลงอุณหภูมิหน่วย Celsius ↔ Fahrenheit

**Input**

- ตัวเลขทศนิยมสูงสุด 3 ตำแหน่ง  
- ตามด้วยตัวอักษร `C` (หน่วย Celsius) หรือ `F` (หน่วย Fahrenheit)  
- ถ้า input ผิดจาก format นี้ให้แสดงว่า `error!`

**Output**

- ถ้า input เป็น Celsius → แปลงเป็น Fahrenheit พร้อมทศนิยม 3 ตำแหน่ง ตามด้วย `F`
- ถ้า input เป็น Fahrenheit → แปลงเป็น Celsius พร้อมทศนิยม 3 ตำแหน่ง ตามด้วย `C`

---

### 🧠 Tags

<span style="background-color: #a98a58; padding: 4px 8px; border-radius: 6px;">Basic I/O</span>  
<span style="background-color: #d4b57c; padding: 4px 8px; border-radius: 6px;">If - else</span>

---

### 🧩 Difficulty

⭐️⭐️⭐️☆☆

---

### 🧪 Sample Test Cases

| Input     | Output     |
|-----------|------------|
| `10.256C`   | 50.461F    |
| 10.5C     | 50.900F    |
| 10C       | 50.000F    |
| .C        | error!     |
| 10.C      | error!     |
| 4DX       | error!     |
| -40F      | -40.000C   |
| .165C     | error!     |

> ⚠️ มี test case ซ่อนอยู่เพิ่มเติมในการทดสอบระบบ

---

### 🔧 Required Headers

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
````

---

### 🧑‍💻 Default Code

```cpp
#include <stdio.h>
// https://cplusplus.com/reference/cstdlib/
#include <stdlib.h>

double CtoF (double celcius) {
    return ((celcius * (9.f/5.f)) + 32.f);
}

double FtoC (double fahrenheit) {
    return ((fahrenheit - 32.f) * (5.f/9.f));
}

int main() {
    char input[20];
}
```

---

📝 **หมายเหตุ**: ห้ามใช้ฟังก์ชันที่ไม่ได้ระบุไว้ใน header ที่อนุญาต

```

---

หากต้องการเวอร์ชันที่ปรับให้เข้ากับเว็บแบบ `Svelte` หรือฝังใน HTML ตรง ๆ ด้วย CSS style sheet ก็สามารถแจ้งเพิ่มเติมได้ครับ!
```
