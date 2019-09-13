# Clinic-Management-simulation-in-C
System panel for a clinic giving two access modes: admin (typical administration mode) and user/client mode

## table of contents
* [Introduction](#introduction)
* [How it should work](#how-it-should-work)
* [System interface design](#system-interface-design)
* [System interface implementation](#System-interface-implementation)

<p></p>


## Introduction
  Imagine a clinic where the poor secretary have to keep a big heavy paper record of all the patients. He should keep in this record some info about each patient (i.e. name, age, gender  ...). that obviously sucks.

<p></p>

  Let's say that the doctor attends the clinic for 2 hours and 30 minutes each day. Each __30 minutes__ make __one slot__. So, we end up with __five slots__ for five patients so one patient can attend in one slot. Our friend ,the secretary, needs to answer all calls asking about free slots and maintain a timetable for these slots to keep track of free slots and who is attending reserved slots.

<p></p>

  obviously, someone should end our friend's misery. For god sake who else would do it if not us. Like we ended a lot of suffering, let's do humanity on more favor.

<p></p>


## How it should work
  __Real quick__, we need our system to maintain data access for __two__ different kinds of users:
  * __admin__ can :
    * view patient records.
    * add new patient record.
    * edit patient record.
    * Delete patient record.
    * View reservation.
    * Reserve a slot with the doctor.
    * Cancel reservation.

  * __normal user__ can :
    * View specific patient record (knowing his ID).
    * View today's reservations.

<p></p>

At least, this is what I could think of for now.

<p></p>

## System interface design
access modes should go like this

<p align="center">
  <img width="600" height="800" src="https://github.com/AlphaArslan/Clinic-Management-simulation-in-C/blob/master/imgs/system_interface.png">
</p>

## System interface implementation
this is the first layer in our program
* __int main()__
  * initializes *record structure*
  * initializes *reservations structure*
  * keeps calling __system_panel()__ until it returns __0__
  * then returns __0__

* __char system_panel(void)__
  * choose between:
    * __Admin Mode__ [calls __admin_mode()__]
    * __User Mode__  [calls __user_mode()__]
    * __Exit__
  * returns:
    * __0__ on __Exit__
    * __1__ otherwise

* __char admin_mode(void)__
  * checks for the password from admin [calls __ask_for_password()__]
    * if __right__:
      * keeps calling __admin_panel()__ until the last returns __0__
      * then returns __0__
    * if __wrong__, returns __1__

* __char user_mode(void)__
  * keeps calling __user_panel()__ until the last returns __0__
  * then returns __0__

* __char ask_for_password(void)__
  * returns __0__ on __3 failed login attempts__
  * returns __1__ on __successful login__

* __char admin_panel(void)__
  * shows what an admin can do
  * returns __0__ on __Log out__
  * returns __1__ otherwise

* __char user_panel(void)__
  * shows what a user can do
  * returns __0__ on __Log out__
  * returns __1__ otherwise
