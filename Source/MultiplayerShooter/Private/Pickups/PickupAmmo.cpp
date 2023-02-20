// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/PickupAmmo.h"
#include "ShooterComponents/CombatComponent.h"
#include "Character/MainCharacter.h"
#include "Components/SphereComponent.h"

APickupAmmo::APickupAmmo()
{
	if (PickupCollision)
	{
		PickupCollision->SetWorldScale3D(FVector(5.f, 5.f, 5.f));
	}
}

void APickupAmmo::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor))
	{
		if (UCombatComponent* Combat = MainCharacter->GetCombat())
		{
			// Update the carried ammo map no matter whether the ammo type is the weapon type.
			const int32 AmmoFromMap = Combat->GetCarriedAmmoFromMap(AmmoType);
			if (AmmoFromMap != -1)
			{
				Combat->UpdateCarriedAmmoMap({AmmoType, AmmoFromMap + PickupAmmo});
			}
			const AWeapon* EquippedWeapon = Combat->GetEquippedWeapon();
			if (EquippedWeapon && AmmoType == EquippedWeapon->GetWeaponType())
			{
				// If the weapon type is the ammo type, then RepNotify, 1. CarriedAmmo 2. CarriedAmmoMap 3. HUD
				Combat->SetCarriedAmmo(AmmoFromMap + PickupAmmo);

				// We automatically reload the weapon once we pick up the ammo and the ammo of the weapon is empty.
				if (EquippedWeapon->IsAmmoEmpty()) Combat->Reload();
			}
		}
		Super::OnSphereBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	}
}
