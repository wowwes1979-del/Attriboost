# Tortuga Tomes (mod-tortuga-tomes)
Adds a `Librarian` that accepts `Books of Knowledge` to increase base attributes, and `Books of Talents` for extra talent points.

Each Book of Knowledge handed in gives one point to spend at the Librarian on Stamina, Strength, Agility, Intellect,
Spirit or Spell Power (+1 per point, capped per stat in the config). A reset refunds every point for gold.

## Install
- Clone this repo to your modules folder as `mod-tortuga-tomes` and rebuild the worldserver.
- Apply the SQL in `data/sql` (characters and world).
- Add the books to your loot templates, quests, reward modules, etc.:
  - Book of Knowledge: item 248000
  - Book of Talents: item 248001
- Spawn the Librarian (npc 248000).
- Copy `conf/tortuga_tomes.conf.dist` to your modules config folder and set `TortugaTomes.Enable = 1`.
- The two books also need their `Item.dbc` rows in a client patch (class, subclass, display id as in the `item_dbc` rows).

## Credits
- TortugaAC (Tortuga Adventure Company)
