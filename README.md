## motor driver control.ino
uses a IR remote to comunicate with the LM293D drives to move the car `forword`, `backward`, `right`, `left` and `stop`
issue detcted sometimes `FFFFFFFF` is picked up by the IR reciver and everything just stops working and this also stops the code from working if the button is pressed

- [x] Fixed the `FFFFFFFF` thing

## code to remove FFFFFFFF.ino
this code is made to remove the biggest issue that was `random value` caught up by the reciver and also removes `FFFFFFFF` by repeating the last stable value until a known value is found

## car basic controls.ino
here im able to controle the car with a IR remote we can perform acctions like `forword`, `backward`, `right`, `left` without the worry of IR issues


