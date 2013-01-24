Resource Exchange (Proof-of-Principle)
======================================

The goal of this repository will be to provide a proof-of-principle
set of examples showing how the proposed Cyclus resource exchange will
function in the following cases. Each of the following cases are
explored for a single time step, i.e., the quality of the received
order is not taken into account.

Case 1: 1 Supplier, 1 Consumer
------------------------------

This case suite is the most trivially simple for a resource
exchange. For a given commodity type, there is is one supplier and one
consumer. We explore the following situations in this suite:

* a resource specification can be matched exactly
* a resource specification can be matched within acceptable bounds
* a resource specification can not be matched within acceptable bounds
* an inter-regional policy excludes matching
* an intra-regional policy excludes matching

Case 2: 1 Supplier, 2 Consumers
-------------------------------

The next simplest case as seen in practice is when there is more than
one consumer for a given supplier. In this case suite we explore
issues regarding supplier capacity constraints as well as
institutional and regional preferences and restrictions. The
situations tested are as followed:

* resource specifications can be matched exactly
* resource specifications combine to be greater than the supplier's
  capacity
* the suppliers capacity is exceeded, but institutional preferences
  drive the consumer selection

Case 3: 2 Suppliers, 1 Consumer
-------------------------------

This case suite is designed to test situations in which there is more
than one supplier from which a consumer can receive resources of a
given commodity type. The following situations are explored:

* no preference differential exists
* a preference differential exists due to quality differences
* there are institution preferences
* there are regional preferences, i.e., one supplier is affected by a
  "tax"
