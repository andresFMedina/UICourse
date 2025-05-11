// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MoneyWidget.h"
#include "Components/TextBlock.h"



void UMoneyWidget::SetCurrentMoney(const int32 NewAmount)
{
	CurrentMoney = NewAmount;
	//TotalMoneyChanged = 0;
	MoneyChanged = 0;
}

void UMoneyWidget::SetMoneyChanged(const int32 NewAmount)
{
	MoneyChanged = NewAmount;
	TotalMoneyChanged += NewAmount;
	TotalMoneyChangedText->SetText(FText::AsNumber(TotalMoneyChanged));
	StartMoneyChangedTimer();
	//MoneyChangedTimerHandle
}

