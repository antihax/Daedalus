// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGUnlockSubsystem.h"

void AFGUnlockSubsystem::GetLifetimeReplicatedProps( TArray< FLifetimeProperty >& OutLifetimeProps) const{ }
void AFGUnlockSubsystem::PreLoadGame_Implementation( int32 saveVersion, int32 gameVersion){ }
AFGUnlockSubsystem* AFGUnlockSubsystem::Get( UWorld* world){ return nullptr; }
AFGUnlockSubsystem* AFGUnlockSubsystem::Get( UObject* worldContext){ return nullptr; }
void AFGUnlockSubsystem::Init(){ }
void AFGUnlockSubsystem::UnlockRecipe( TSubclassOf<  UFGRecipe > recipe){ }
void AFGUnlockSubsystem::UnlockScannableResource( TSubclassOf<  UFGResourceDescriptor > newResource){ }
void AFGUnlockSubsystem::UnlockMap(){ }
void AFGUnlockSubsystem::UnlockBuildEfficiency(){ }
void AFGUnlockSubsystem::UnlockBuildOverclock(){ }
void AFGUnlockSubsystem::UnlockInventorySlots( int32 numSlotsToUnlock){ }
void AFGUnlockSubsystem::UnlockArmEquipmentSlots( int32 numSlotsToUnlock){ }
void AFGUnlockSubsystem::OnSchematicPurchased( TSubclassOf<  UFGSchematic > newSchematic){ }
void AFGUnlockSubsystem::SetNumOfAdditionalInventorySlots( int32 newNumSlots){ }
void AFGUnlockSubsystem::SetNumAdditionalArmEquipmentSlots( int32 newNumSlots){ }
void AFGUnlockSubsystem::SendMessageToAllPlayers( TSubclassOf<  UFGMessageBase > inMessage){ }
