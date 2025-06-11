# HanoiTower

หอคอย hanoi (HanoiTower) คือเกมส์ที่มีกฏง่ายๆ คือให้ขยับจาน(disk) จาก เสา(peg)ซ้ายสุดไปขวาสุด โดย สามารถขยับได้ทีละจาน และ ห้ามวางจานที่ใหญ่กว่าเหนือจานเล็ก แค่นี้เอง ง่ายๆเนาะ แต่มันดันพิเศษตรงที่ ยิ่งจานมากขึ้นเรื่อยๆ ยิ่งยากขึ้นเท่าตัว เช่น 3 จาน สามารถแก้ได้ดังนี้ Move disk 1 from peg A to peg C Move disk 2 from peg A to peg B Move disk 1 from peg C to peg B Move disk 3 from peg A to peg C Move disk 1 from peg B to peg A Move disk 2 from peg B to peg C Move disk 1 from peg A to peg C จะเห็นว่าต้องขยับ 7 รอบ แต่ถ้าพี่เพิ่มเป็น 4 จาน เราจะต้องขยับ 15 รอบ ถ้าพี่มี 7 จาน พี่ต้องขยับถึง 127 รอบ!!! สรุปคือถ้าพี่มี n จานพี่จะต้อง ขยับ (2^n)-1 รอบ แต่การคำนวนแค่นี้มันง่ายเกินไป พ่จะให้เราโชว์มาเลยว่าจะขยับยังไงง โดยเสาแทนด้วย ABC และ จานแทนด้วยตัวเลข

## Solution

```c
// Your code here
```