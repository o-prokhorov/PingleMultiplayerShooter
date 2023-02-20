// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/Pickup.h"
#include "PickupHealth.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSHOOTER_API APickupHealth : public APickup
{
	GENERATED_BODY()

public:
	APickupHealth();
	
protected:
	virtual void OnSphereBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	) override;

private:
	UPROPERTY(EditAnywhere, Category = Health)
	float HealingAmount;

	UPROPERTY(EditAnywhere, Category = Health)
	float Duration;
};
