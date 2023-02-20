// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AnnouncementWidget.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSHOOTER_API UAnnouncementWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TimeText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Announce_0;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Announce_1;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* WinText;
};
