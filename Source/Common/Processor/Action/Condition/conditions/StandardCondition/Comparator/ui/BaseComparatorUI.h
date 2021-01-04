/*
  ==============================================================================

    BaseComparatorUI.h
    Created: 2 Nov 2016 11:35:11pm
    Author:  bkupe

  ==============================================================================
*/

#pragma once

#include "../BaseComparator.h"

class BaseComparatorUI :
	public Component,
	public Parameter::AsyncListener
{
public:
	BaseComparatorUI(BaseComparator * comparator);
	virtual ~BaseComparatorUI();

	BaseComparator * comparator;
	WeakReference<Inspectable> comparatorRef;

	std::unique_ptr<EnumParameterUI> compareFuncUI;

	std::unique_ptr<ControllableEditor> refEditor;
	void resized() override;

	void newMessage(const Parameter::ParameterEvent &e) override;
};