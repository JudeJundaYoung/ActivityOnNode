# ActivityOnNode

# 1.Introduction

Activity-On-Node is a kind of diagram that shows the relationships between different activities in construction.

By linking with arrow, the sequences of activies are evidently show on the diagram.

# 2. Key Words

## 2.1 Members of Activity

Each node represents one independant activity. Basically, there are 7 members for one node: Early Start, Early Finish(or Early End), Late Start, Late Finish(or Late Finish), Duration, Act ID and Description.

- Early Start: The earliest start date of an activity.

-Early Finish: The earliest finish date of an activity.

-Late Start: The latest start date of an activity.

Late Finish: The latest finish date of an activity.

Duration: The minimum time cost of an activity.

Act ID: The unique ID of an activity.

Description: Brief summary of an activity.

## 2.2 Delay

Due to the uncertainty of construction, delay happens frequently.

Delay can leads to the change of finish date and the start date of successor. In the most serious situation, the delay of one single activity can extend the duration of the whole construction.

## 2.3 Float

Generally, there are 4 kinds of float in construction: total float, free float, interfering float and independant float。

Total float: the maximum delay time of one activity which won't do harm to the duration of the whole construction.

Free float: the maximum delay time of one activity which won't do harm to the early start time of its successor.

## 2.4 Relationship

Generally, there are 4 kinds of relationships between different independant activities.

Finish-Start: the most prevalent one. The successor won't start until its predecessor is finished.

Finish-Finish: the successor should be finished when its predecessor is finished.

Start-Start: the succesor should start when its predecessor starts.

Start-Finish: the most rare one. The successor should be finished when its predecessor starts.

This project is based on the Finish-Start relationship/sequence, which means the start time of successor should not be earlier than any of its predecessors.

# 3.Activity-On-Node

## 1. Concept

The AON diagram is consisted by arrows and node.

## 2. Arrow

The arrow should be drawn from left to right to demonstrate the sequnces.

The arrow should be started at the right side of node to avoid mistaking the sequnces.

Make the crossing of arrows as few as possible.

When crossing, draw a fly line to highlight.

## 3.Node

Node should be drawn in rectangle.

There should be a start node and end node to illustrate the beginning and end(activity can act as one).

# 4.Critical Path

## 4.1 Introduction

Critical Path is one determines the duration of construction.

It is consisted of critical activities.

Critical activities have the latest start and finish time in their siblings.

The sum of their duration, basically, is the duration of the whole construction.

## 4.2 Attribute

All projects have at least one critical path.

All critical activities belong to critical path.

Delay in critical activities/path extends duration of the construction.

Noncritical activities can be delayed more than one day without effecting the duration of construction.

To decrease the duration, focus on shortening critical activities.

Decreasing the duration of critical activities can generate new critical activity or critical path.

# 5.Objectives

By entering the elementary members of node and there sequences, the user can get a generated AON diagram.

Different kinds of float will be shown automatically.

GUI(Perhaps :) ).
