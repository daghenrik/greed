#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include <ncurses.h>

#include "creature.h"
#include "room.h"

Room::~Room()
{
}

Room* Room::perform_action(const std::string& kbd_input, bool& valid_input)
{
    if (actions.find(kbd_input) != actions.end())
    {
        valid_input = true;
        actions.at(kbd_input)->exec();
    }
    return this;
}

Room* Room::next_room(const std::string& kbd_input, bool& valid_input)
{
    if (exits.find(kbd_input) == exits.end())
    {
        return this;
    }
    valid_input = true;
    return exits.at(kbd_input);
}

void Room::enter() const
{
    display();
}

void Room::display() const
{
    printw("%s\n", desc.c_str());

    // Display creatures in the room.
    for (std::vector<std::unique_ptr<Creature>>::const_iterator creature = creatures.begin();
         creature != creatures.end(); ++creature)
    {
        attron(COLOR_PAIR(1));
        printw("%s\n", (*creature)->name.c_str());
        attroff(COLOR_PAIR(1));
    }

    // Display items in the room.
    for (std::vector<std::unique_ptr<Item>>::const_iterator item = items.begin();
         item != items.end(); ++item)
    {
        attron(COLOR_PAIR(2));
        printw("%s\n", (*item)->name.c_str());
        attroff(COLOR_PAIR(2));
    }

    // Display exits from the room.
    printw("Exits: ");

    auto exit = exits.begin();

    if (exit == exits.end() || exit->first == "unnamed")
    {
        printw("None.");
    }
    else
    {
        for (; exit != exits.end(); ++exit)
        {
            printw("%s", exit->first.c_str());

            if (std::distance(exit, exits.end()) > 1)
            {
                printw(", ");
            }
        }
    }
    printw("\n");
}
