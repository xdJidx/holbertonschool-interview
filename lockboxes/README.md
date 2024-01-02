# Lockboxes

## Tasks

### 0. Lockboxes
You have n number of locked boxes in front of you. Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.<br>

Write a method that determines if all the boxes can be opened.

- Prototype: def canUnlockAll(boxes)
- boxes is a list of lists
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
 - There can be keys that do not have boxes
- The first box boxes[0] is unlocked
- Return True if all boxes can be opened, else return False
```
carrie@ubuntu:~/lockboxes$ cat main_0.py
#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))

carrie@ubuntu:~/lockboxes$
```
```
carrie@ubuntu:~/lockboxes$ ./main_0.py
True
True
False
carrie@ubuntu:~/lockboxes$
```

Firstly, I initialize a list called unlocked_boxes[] that defines if the boxes are unlocked. They are all set to False by default except for boxes[0].
<br>
Then, I create a list of keys named keys[] containing the initially available keys in boxes[0].
<br>
Next, as long as there are available keys and keys is not empty, I take one of the keys using pop.
<br>
I check if this key opens a new box that is not yet unlocked, i.e., if unlocked_boxes[key] is False. If so, it becomes True.
<br>
Consequently, I add the newly available keys in this box to my keys list.
Finally, at the end of the process, I check if all the boxes are True.
<br>
If they are, return True.
If not, return False.
