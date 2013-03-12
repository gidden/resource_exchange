Resource Exchange (Proof-of-Principle)
======================================

The goal of this repository will be to provide a proof-of-principle set of
examples showing how the proposed Cyclus resource exchange will function in the
following example cases.

The resource exchange is designed to match suppliers with consumers in a
three-step process.

The first step is for consumers to "post" their consumption needs, i.e. their
"demand". Consumers are allowed to "over post", i.e., request more than they
actually need if a corresponding constraint accompanies that request. For
example, a facility could request fuel as either fire or coal, but must denote
that it will take only one of the two. While their preference between the two
competing sources is known at this time, that state is queried in the third
step. This posting is termed a "request for bid".

The second step allows supplier entities to respond to the board of posted
demands. In general, this step is simple: suppliers know which commodities they
produce and at what maximum capacity they produce them. Accordingly, responses
can be posted to each consumer requesting a resource in their production
category. In the current formulation, capacity restrictions must be linear
functions of the demand, but may depend on specific qualities of the demand
(e.g. uranium enrichment and SWUs), because these are static at solution time
and can thus be evaluated and modeled as a constant. This posting is termed a
"response for requests for bids" and effectively defines the possible arcs
between consumers and producers. It should be noted that arcs can transend
commodities, i.e., this is a multi-commodity problem.

The third step is for consumers and their managers to assign a preference score
to each bid. In our system, managers are institutions and regions, where each is
allowed to affect the overal preference through modifiers. The facilities
themselves set the base preference score, which can be simply a funciton of the
commodity or, in a more advanced way, a funciton of both the commodity and
quality thereof. For example, a facility can say apriori that it prefers wood
over coal, but a region can inform the preference that no coal is allowed. It is
at this step that timeliness can be assessed, i.e., a facility can give a
preference of 0 to a response that will arrive too late. It is also at this
stage that consumers can group bid responses. For example, a facility could say
that it will accept only an order of wood or only an order of coal. Furthermore,
it can denote that it will only accept whole orders, i.e. all of its order must
come from a single supplier. This models the reality of the fuel cycle, but
transforms the problem from a linear program (LP) to a mixed integer/linear
program (MILP).

testing

.. math::

   \sum{h \in H} c(h)}



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

Case 4: 1 Resource, 2 Commodities
---------------------------------

This is a singular case in which a supplier has one resource that can
be traded in two different "markets". It is designed to mirror the
issue of sending used fuel to either a repository or to a recycling
facility.
