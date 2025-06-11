# Un-Pig the Latin

พี่ได้รับจดหมายมาแต่พี่อ่านไม่เข้าใจ แต่มีคนมาใบ้บอกว่ามันเป็นการเขียนแบบ Pig Latin

## 🐷 Pig Latin คือ?
Pig Latin เป็นภาษาลับ ที่มีกฎดังต่อไปนี้
- ถ้าคำนั้นขึ้นต้นด้วยพยัญชนะ ให้ย้ายตัวพยัญชนะตัวหน้าไปใว้ข้างหลังสุด แล้วต่อท้ายด้วย ay
เช่น
`hello -> elloh -> ellohay`

- แต่ถ้าเริ่มด้วยสระ (a, e, i, o, u) ให้ต่อท้ายด้วย way เช่น
`orange -> orangeway`

## 🎯 เป้าหมาย
เขียนโปรแกรมที่แปลงคำศัพท์ใน Pig Latin กลับเป็นคำปกติ

## 🗨️ คำอธิบาย Input-Output
โปรแกรมจะรับ Input `str` 1 คำที่เป็น**พิมพ์เล็กเท่านั้น** เช่น
`ellohay`, `aterway`
ถ้าหากกรอกนอกเหนือให้โปรแกรมแสดง `Invalid`

ถ้าคำนั้นแปลได้ ให้แสดง
`Original Word: <original>` เช่น `Original Word: hello`

**หมายเหตุ**:
- กรณีแปลคำที่จบด้วย way อาจมาได้จาก 2 คำ เช่น
`water -> aterway` และ `ater -> aterway`
ในที่นี้ให้แสดงเป็นรูปแบบ
`Possible Word: <word_1>,<word_2>` เช่น `Possible Word: ater, water`
- แต่ถ้าคำที่จบด้วย ay แต่มีตัวนำเป็นสระ เป็นกรณีที่ไม่สามารถเกิดขึ้นได้ เช่น
`rangeoay -> orange` (orange ควรมาจาก orangeway ไม่ใช่ rangeoay) ให้แสดง `Invalid`
- แต่ถ้าคำนั้นไม่อยู่ในรูปแบบของ Pig Latin เลยให้แสดง `Invalid`

### รูปภาพประกอบ
![Pig Latin](https://external-content.duckduckgo.com/iu/?u=http%3A%2F%2Fdrive.google.com/uc?id=1iQ0p1M51Q2O80Rdns693P1MOzc7AvbbS)

## Solution

```c
// Your code here
```