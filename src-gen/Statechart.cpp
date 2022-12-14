/** Generated by YAKINDU Statechart Tools code generator. */

#include "Statechart.h"

/*! \file
Implementation of the state machine 'Statechart'
*/




Statechart::Statechart() :
	evButtonUnpressed_raised(false),
	evButtonPressed_raised(false),
	evButtonPressed_value(0),
	viMyCounter(0),
	viTecla(0),
	timerService(sc_null),
	isExecuting(false)
{
	for (sc_ushort state_vec_pos = 0; state_vec_pos < maxOrthogonalStates; ++state_vec_pos)
		stateConfVector[state_vec_pos] = Statechart_last_state;
	
	clearInEvents();
}

Statechart::~Statechart()
{
}


using namespace statechart_events;

SctEvent* Statechart::getNextEvent()
{
	SctEvent* nextEvent = 0;
	
	if(!inEventQueue.empty()) {
		nextEvent = inEventQueue.front();
		inEventQueue.pop_front();
	}
	
	return nextEvent;
}

void Statechart::dispatch_event(SctEvent * event)
{
	if(event == 0) {
		return;
	}
	switch(event->name)
	{
		case evButtonUnpressed:
		case evButtonPressed:
		{
			iface_dispatch_event(event);
			break;
		}
		case Statechart_Button_DEBOUNCE_time_event_0:
		{
			timeEvents[0] = true;
			break;
		}
		default:
			/* do nothing */
			break;
	}
	delete event;
}

void Statechart::iface_dispatch_event(SctEvent * event)
{
	switch(event->name)
	{
		case evButtonUnpressed:
		{
			internal_raiseEvButtonUnpressed();
			break;
		}
		case evButtonPressed:
		{
			SctEvent__evButtonPressed * e = static_cast<SctEvent__evButtonPressed*>(event);
			if(e != 0) {
				internal_raiseEvButtonPressed(e->value);
			}
			break;
		}
		default:
			/* do nothing */
			break;
	}
}
void Statechart::internal_dispatch_event(SctEvent * event)
{
	switch(event->name)
	{
		default:
			/* do nothing */
			break;
	}
}

StatechartEventName Statechart::getTimedEventName(sc_eventid evid)
{
	if (evid == (sc_eventid)(&timeEvents[0])) {
		return Statechart_Button_DEBOUNCE_time_event_0;
	}
	return invalid_event;
}



sc_boolean Statechart::isActive() const
{
	return stateConfVector[0] != Statechart_last_state;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean Statechart::isFinal() const
{
   return false;}

sc_boolean Statechart::check() {
	if(timerService == sc_null) {
		return false;
	}
	return true;
}


void Statechart::setTimerService(sc::timer::TimerServiceInterface* timerService_)
{
	this->timerService = timerService_;
}

sc::timer::TimerServiceInterface* Statechart::getTimerService()
{
	return timerService;
}

sc_integer Statechart::getNumberOfParallelTimeEvents() {
	return parallelTimeEventsCount;
}

void Statechart::raiseTimeEvent(sc_eventid evid)
{
	if ((evid >= (sc_eventid)timeEvents) && (evid < (sc_eventid)(&timeEvents[timeEventsCount])))
	{
		inEventQueue.push_back(new TimedSctEvent(getTimedEventName(evid)));
		runCycle();
	}
}


sc_boolean Statechart::isStateActive(StatechartStates state) const
{
	switch (state)
	{
		case Button_DEBOUNCE :
		{
			return (sc_boolean) (stateConfVector[SCVI_BUTTON_DEBOUNCE] == Button_DEBOUNCE);
			break;
		}
		case Button_BUTTON_UNPRESSED :
		{
			return (sc_boolean) (stateConfVector[SCVI_BUTTON_BUTTON_UNPRESSED] == Button_BUTTON_UNPRESSED);
			break;
		}
		case Button_BUTTON_PRESSED :
		{
			return (sc_boolean) (stateConfVector[SCVI_BUTTON_BUTTON_PRESSED] == Button_BUTTON_PRESSED);
			break;
		}
		case Button_VALIDATE :
		{
			return (sc_boolean) (stateConfVector[SCVI_BUTTON_VALIDATE] == Button_VALIDATE);
			break;
		}
		default:
		{
			/* State is not active*/
			return false;
			break;
		}
	}
}

/* Functions for event evButtonUnpressed in interface  */
void Statechart::raiseEvButtonUnpressed()
{
	inEventQueue.push_back(new SctEvent__evButtonUnpressed(evButtonUnpressed));
        runCycle();
}
void Statechart::internal_raiseEvButtonUnpressed()
{
	evButtonUnpressed_raised = true;
}
/* Functions for event evButtonPressed in interface  */
void Statechart::raiseEvButtonPressed(uint32_t evButtonPressed_)
{
	inEventQueue.push_back(new SctEvent__evButtonPressed(evButtonPressed, evButtonPressed_));
        runCycle();
}
void Statechart::internal_raiseEvButtonPressed(uint32_t evButtonPressed_)
{
	evButtonPressed_value = evButtonPressed_;
	evButtonPressed_raised = true;
}

// implementations of all internal functions
/* Entry action for state 'DEBOUNCE'. */
void Statechart::enact_Button_DEBOUNCE()
{
	/* Entry action for state 'DEBOUNCE'. */
	timerService->setTimer(this, (sc_eventid)(&timeEvents[0]), 100, false);
}

/* Entry action for state 'BUTTON_PRESSED'. */
void Statechart::enact_Button_BUTTON_PRESSED()
{
	/* Entry action for state 'BUTTON_PRESSED'. */
	opLedUpdate();
	viTecla = evButtonPressed_value;
	viMyCounter++;
}

/* Exit action for state 'DEBOUNCE'. */
void Statechart::exact_Button_DEBOUNCE()
{
	/* Exit action for state 'DEBOUNCE'. */
	timerService->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
}

/* 'default' enter sequence for state DEBOUNCE */
void Statechart::enseq_Button_DEBOUNCE_default()
{
	/* 'default' enter sequence for state DEBOUNCE */
	enact_Button_DEBOUNCE();
	stateConfVector[0] = Button_DEBOUNCE;
}

/* 'default' enter sequence for state BUTTON_UNPRESSED */
void Statechart::enseq_Button_BUTTON_UNPRESSED_default()
{
	/* 'default' enter sequence for state BUTTON_UNPRESSED */
	stateConfVector[0] = Button_BUTTON_UNPRESSED;
}

/* 'default' enter sequence for state BUTTON_PRESSED */
void Statechart::enseq_Button_BUTTON_PRESSED_default()
{
	/* 'default' enter sequence for state BUTTON_PRESSED */
	enact_Button_BUTTON_PRESSED();
	stateConfVector[0] = Button_BUTTON_PRESSED;
}

/* 'default' enter sequence for state VALIDATE */
void Statechart::enseq_Button_VALIDATE_default()
{
	/* 'default' enter sequence for state VALIDATE */
	stateConfVector[0] = Button_VALIDATE;
}

/* 'default' enter sequence for region Button */
void Statechart::enseq_Button_default()
{
	/* 'default' enter sequence for region Button */
	react_Button__entry_Default();
}

/* Default exit sequence for state DEBOUNCE */
void Statechart::exseq_Button_DEBOUNCE()
{
	/* Default exit sequence for state DEBOUNCE */
	stateConfVector[0] = Statechart_last_state;
	exact_Button_DEBOUNCE();
}

/* Default exit sequence for state BUTTON_UNPRESSED */
void Statechart::exseq_Button_BUTTON_UNPRESSED()
{
	/* Default exit sequence for state BUTTON_UNPRESSED */
	stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for state BUTTON_PRESSED */
void Statechart::exseq_Button_BUTTON_PRESSED()
{
	/* Default exit sequence for state BUTTON_PRESSED */
	stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for state VALIDATE */
void Statechart::exseq_Button_VALIDATE()
{
	/* Default exit sequence for state VALIDATE */
	stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for region Button */
void Statechart::exseq_Button()
{
	/* Default exit sequence for region Button */
	/* Handle exit of all possible states (of Statechart.Button) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case Button_DEBOUNCE :
		{
			exseq_Button_DEBOUNCE();
			break;
		}
		case Button_BUTTON_UNPRESSED :
		{
			exseq_Button_BUTTON_UNPRESSED();
			break;
		}
		case Button_BUTTON_PRESSED :
		{
			exseq_Button_BUTTON_PRESSED();
			break;
		}
		case Button_VALIDATE :
		{
			exseq_Button_VALIDATE();
			break;
		}
		default:
			/* do nothing */
			break;
	}
}

/* Default react sequence for initial entry  */
void Statechart::react_Button__entry_Default()
{
	/* Default react sequence for initial entry  */
	opLedInit();
	opButtonInit();
	viMyCounter = 0;
	enseq_Button_BUTTON_UNPRESSED_default();
}

sc_integer Statechart::react(const sc_integer transitioned_before) {
	/* State machine reactions. */
	return transitioned_before;
}

sc_integer Statechart::Button_DEBOUNCE_react(const sc_integer transitioned_before) {
	/* The reactions of state DEBOUNCE. */
	sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (timeEvents[0])
		{ 
			exseq_Button_DEBOUNCE();
			timeEvents[0] = false;
			enseq_Button_VALIDATE_default();
			react(0);
			transitioned_after = 0;
		} 
	} 
	/* If no transition was taken then execute local reactions */
	if ((transitioned_after) == (transitioned_before))
	{ 
		transitioned_after = react(transitioned_before);
	} 
	return transitioned_after;
}

sc_integer Statechart::Button_BUTTON_UNPRESSED_react(const sc_integer transitioned_before) {
	/* The reactions of state BUTTON_UNPRESSED. */
	sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (evButtonPressed_raised)
		{ 
			exseq_Button_BUTTON_UNPRESSED();
			enseq_Button_DEBOUNCE_default();
			react(0);
			transitioned_after = 0;
		} 
	} 
	/* If no transition was taken then execute local reactions */
	if ((transitioned_after) == (transitioned_before))
	{ 
		transitioned_after = react(transitioned_before);
	} 
	return transitioned_after;
}

sc_integer Statechart::Button_BUTTON_PRESSED_react(const sc_integer transitioned_before) {
	/* The reactions of state BUTTON_PRESSED. */
	sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (evButtonUnpressed_raised)
		{ 
			exseq_Button_BUTTON_PRESSED();
			enseq_Button_BUTTON_UNPRESSED_default();
			react(0);
			transitioned_after = 0;
		} 
	} 
	/* If no transition was taken then execute local reactions */
	if ((transitioned_after) == (transitioned_before))
	{ 
		transitioned_after = react(transitioned_before);
	} 
	return transitioned_after;
}

sc_integer Statechart::Button_VALIDATE_react(const sc_integer transitioned_before) {
	/* The reactions of state VALIDATE. */
	sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (evButtonPressed_raised)
		{ 
			exseq_Button_VALIDATE();
			enseq_Button_BUTTON_PRESSED_default();
			react(0);
			transitioned_after = 0;
		}  else
		{
			if (evButtonUnpressed_raised)
			{ 
				exseq_Button_VALIDATE();
				enseq_Button_BUTTON_UNPRESSED_default();
				react(0);
				transitioned_after = 0;
			} 
		}
	} 
	/* If no transition was taken then execute local reactions */
	if ((transitioned_after) == (transitioned_before))
	{ 
		transitioned_after = react(transitioned_before);
	} 
	return transitioned_after;
}

void Statechart::clearInEvents() {
	evButtonUnpressed_raised = false;
	evButtonPressed_raised = false;
	timeEvents[0] = false;
}

void Statechart::microStep() {
	switch(stateConfVector[ 0 ])
	{
		case Button_DEBOUNCE :
		{
			Button_DEBOUNCE_react(-1);
			break;
		}
		case Button_BUTTON_UNPRESSED :
		{
			Button_BUTTON_UNPRESSED_react(-1);
			break;
		}
		case Button_BUTTON_PRESSED :
		{
			Button_BUTTON_PRESSED_react(-1);
			break;
		}
		case Button_VALIDATE :
		{
			Button_VALIDATE_react(-1);
			break;
		}
		default:
			/* do nothing */
			break;
	}
}

void Statechart::runCycle() {
	/* Performs a 'run to completion' step. */
	if (isExecuting)
	{ 
		return;
	} 
	isExecuting = true;
	dispatch_event(getNextEvent());
	do
	{ 
		microStep();
		clearInEvents();
		dispatch_event(getNextEvent());
	} while (((evButtonUnpressed_raised) || (evButtonPressed_raised)) || (timeEvents[0]));
	isExecuting = false;
}

void Statechart::enter() {
	/* Activates the state machine. */
	if (isExecuting)
	{ 
		return;
	} 
	isExecuting = true;
	/* Default enter sequence for statechart Statechart */
	enseq_Button_default();
	isExecuting = false;
}

void Statechart::exit() {
	/* Deactivates the state machine. */
	if (isExecuting)
	{ 
		return;
	} 
	isExecuting = true;
	/* Default exit sequence for statechart Statechart */
	exseq_Button();
	isExecuting = false;
}

/* Can be used by the client code to trigger a run to completion step without raising an event. */
void Statechart::triggerWithoutEvent() {
	runCycle();
}

