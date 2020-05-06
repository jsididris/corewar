.name "MrFork"
.comment "Un Zork qui fork"
sti r1, %:here, %1
and r2, r2, r2
here: live %42
fork %:here

