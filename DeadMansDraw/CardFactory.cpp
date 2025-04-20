#include "Cannon.h"
#include "Chest.h"
#include "Key.h"
#include "Sword.h"
#include "Hook.h"
#include "Oracle.h"
#include "Map.h"
#include "Mermaid.h"
#include "Kraken.h"
#include "Anchor.h"

std::unique_ptr<Card> instantiateCard(Card::CardType type, int value) {
    
    switch (type) {
    case Card::CardType::Cannon:
        return std::make_unique<Cannon>(value);
    case Card::CardType::Chest:
        return std::make_unique<Chest>(value);
    case Card::CardType::Key:
        return std::make_unique<Key>(value);
    case Card::CardType::Sword:
        return std::make_unique<Sword>(value);
    case Card::CardType::Hook:
        return std::make_unique<Hook>(value);
    case Card::CardType::Oracle:
        return std::make_unique<Oracle>(value);
    case Card::CardType::Map:
        return std::make_unique<Map>(value);
    case Card::CardType::Mermaid:
        return std::make_unique<Mermaid>(value);
    case Card::CardType::Kraken:
        return std::make_unique<Kraken>(value);
    case Card::CardType::Anchor:
        return std::make_unique<Anchor>(value);
}