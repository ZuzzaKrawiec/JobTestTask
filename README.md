# JobTestTask
Titan GameZ job test task

Recruitment task:

Task prerequisites:
- use Unreal Engine 5 latest version,
- implementation should be a mixture of c++ & blueprints,
- use https://github.com/ as repository,
- sent repository link with task implementation to rekrutacja@titangamez.com.

What to do:
- level composition,
- plane floor,
- single agent represented as Capsule primitive,
- 3 buildings represented as Cube primitive,
- immovable camera,
- directional lightning.

Description:
- agent can be assigned to a single Building via UI,
- assignment triggers agents to move towards Building,
- when movement is done all Interactions occur at once,

Interactions:
- interaction A: Agent changes color (single use),
- interaction B: Agent jumps until unassign,
- nteraction C: play sound until unassign.

Buildings:
- building A: consists of Interaction A,
- building B: consists of Interaction A + B,
- building C: consists of Interaction A + B + C.

Bonus:
- arrange code architecture according to the “Composition Over Inheritance” approach.

Notes:
- visuals and redundant mechanics are not going to be evaluated,
- feel free to contact us if something is not clear.
