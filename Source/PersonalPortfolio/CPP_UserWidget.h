// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PERSONALPORTFOLIO_API UCPP_UserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* score = nullptr;

public:
	void UpdateText(int scoreToScreen);
};
