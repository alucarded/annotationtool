#pragma once

public delegate void SendObjectData(System::String^ name, System::String^ description, double aspect_ratio /* w/h */);

public interface class IAddObjectView
{
public:
    virtual void AddObject(System::String^ name, System::String^ description) = 0;
    event SendObjectData^ ObjectAdded;
};