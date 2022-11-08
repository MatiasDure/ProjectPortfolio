// Fill out your copyright notice in the Description page of Project Settings.

#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));}
#include "CPP_UserWidget.h"
#include "Components/TextBlock.h"
#include "string"

void UCPP_UserWidget::UpdateText(int scoreToScreen)
{
	if (this->score) score->SetText(FText::AsNumber(scoreToScreen));
}
