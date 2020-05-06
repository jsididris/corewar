.name "MrZjmp"
.comment "Un Zork qui zjmp"
sti r1, %:here, %1
and r2, r2, r2
here: live %42
zjmp %:here

