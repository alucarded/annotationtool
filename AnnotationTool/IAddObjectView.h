#pragma once

public delegate void SendObjectData(System::String^ name, double aspect_ratio /* w/h */);

public interface class IAddObjectView
{
public:
    virtual void AddObject(System::String^ name) = 0;
    event SendObjectData^ ObjectAdded;
};