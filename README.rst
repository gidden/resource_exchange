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
and can thus be evaluated and modeled as a constant. Furthermore, a producer can
provide more than one such capacity restriction. For example, an enriched
uranium provider could have capacities related to both SWU and natural uranium
reserves. This posting is termed a "response for requests for bids" and
effectively defines the possible arcs between consumers and producers. It should
be noted that consumers can request different commodities to meet the same
demand, i.e., this is a multi-commodity problem.

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
program (MILP). Finally, a cost translation mapping is applied to the set of
preferences in order to assume the form of a minimum cost problem.

Complexities
------------

A number of complexities are involved in this problem. We break down use cases
into those of increasing complexity:

Supply Doesn't Meeting Demand
-----------------------------

For any problem of this type to be feasible, overall supply must be greater than
demand. However, this is not always the case for automated simulation. The
general solution technique for this problem is to create artificial source nodes
that have arbitrarily high costs and capacities. Accordingly, any amount of
supply met by these nodes is noted and removed from the solution before
returning the solution.

Multiple Supply Constraints for a Commodity
-------------------------------------------

A supplier can have more than one constraint on its capacity of a commodity,
given the quantity and quality of each demand. A likely way forward is to say:
for each resource request in the exchange, return a set of capacity values
associated with the registered constraints.

Demand Can be Met by Multiple Commodities
-----------------------------------------

We wish to model demand that can be met by multiple commodities, i.e. a demander
provides a quantity and set of commodities that meet its demand. The commodities
which are chosen are a function of capacity and cost.

Demand Must be Met by a Single Provider
---------------------------------------

A further complication, adding integer decision variables, is that in addition
to the previous case, a subset of those demanders must have their demand met by
a single provider. This addition allows us to model reactors that can use
multiple types of fuel but not mutually. For example, a reactor could use UOx or
MOx, but not a mixture.
