# Clinic-Management-simulation-in-C
System panel for a clinic giving two access modes: admin (typical administration mode) and user/client mode

## table of contents
* [Introduction](#introduction)
* [How it should work](#how-it-should-work)

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
