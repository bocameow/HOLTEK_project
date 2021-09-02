alias ultrasound="g++ -o ultrasound.out Ultrasound.cxx -lwiringPi; ./ultrasound.out; rm ultrasound.out"
alias redline="g++ -o redline.out Redline.cxx -lwiringPi; ./redline.out; rm redline.out"
alias motor="g++ -o motor.out motor.cxx -lwiringPi; ./motor.out; rm motor.out"
alias backmotor="g++ -o backmotor.out turnback.cxx -lwiringPi; ./backmotor.out; rm backmotor.out"
alias all="g++ -o all.out ALL.cxx -lwiringPi; ./all.out; rm all.out"

alias init="git init"
alias add="git add ."
alias push="git push -u origin master"
