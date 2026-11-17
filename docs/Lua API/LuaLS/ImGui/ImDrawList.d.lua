---@meta

---@class ImDrawList
ImDrawList = {}

---@param pos Vector2 
---@param col integer 
---@param text string 
function ImDrawList:AddText(pos, col, text) end

---@param fontSize number 
---@param pos Vector2 
---@param col integer 
---@param text string 
---@param wrapWidth number? 
function ImDrawList:AddText(fontSize, pos, col, text, wrapWidth) end

---@param p1 Vector2 
---@param p2 Vector2 
---@param col integer 
---@param thickness number? 
function ImDrawList:AddLine(p1, p2, col, thickness) end

---@param points { [integer]: Vector2 } An array of Vector2 objects. **MUST** be a contiguous Vector2 array, else the function will throw.
---@param numPoints integer 
---@param col integer 
---@param flags integer [ImDrawFlags](lua://ImDrawFlags)
---@param thickness number 
function ImDrawList:AddPolyLine(points, numPoints, col, flags, thickness) end

---@param pMin Vector2 
---@param pMax Vector2 
---@param col integer 
---@param rounding number? 
function ImDrawList:AddRect(pMin, pMax, col, rounding) end

---@param pMin Vector2 
---@param pMax Vector2 
---@param col integer 
---@param rounding number 
---@param flags integer? Optional [ImDrawFlags](lua://ImDrawFlags)
function ImDrawList:AddRect(pMin, pMax, col, rounding, flags) end

---@param pMin Vector2 
---@param pMax Vector2 
---@param col integer 
---@param rounding number 
---@param flags integer [ImDrawFlags](lua://ImDrawFlags)
---@param thickness number? 
function ImDrawList:AddRect(pMin, pMax, col, rounding, flags, thickness) end

---@param pMin Vector2 
---@param pMax Vector2 
---@param col integer 
---@param rounding number? 
function ImDrawList:AddRectFilled(pMin, pMax, col, rounding) end

---@param pMin Vector2 
---@param pMax Vector2 
---@param col integer 
---@param rounding number 
---@param flags integer? Optional [ImDrawFlags](lua://ImDrawFlags)
function ImDrawList:AddRectFilled(pMin, pMax, col, rounding, flags) end

---@param center Vector2 
---@param radius number 
---@param col integer 
---@param numSegments integer? 
function ImDrawList:AddCircle(center, radius, col, numSegments) end

---@param center Vector2 
---@param radius number 
---@param col integer 
---@param numSegments integer 
---@param thickness number? 
function ImDrawList:AddCircle(center, radius, col, numSegments, thickness) end

---@param center Vector2 
---@param radius number 
---@param col integer 
---@param numSegments integer? 
function ImDrawList:AddCircleFilled(center, radius, col, numSegments) end

---@param center Vector2 
---@param radius number 
---@param col integer 
---@param numSegments integer 
---@param thickness number? 
function ImDrawList:AddNgon(center, radius, col, numSegments, thickness) end

---@param center Vector2 
---@param radius number 
---@param col integer 
---@param numSegments integer 
function ImDrawList:AddNgonFilled(center, radius, col, numSegments) end

---@param p1 Vector2 
---@param p2 Vector2 
---@param p3 Vector2 
---@param p4 Vector2 
---@param col integer 
---@param thickness number? 
function ImDrawList:AddQuad(p1, p2, p3, p4, col, thickness) end

---@param p1 Vector2 
---@param p2 Vector2 
---@param p3 Vector2 
---@param p4 Vector2 
---@param col integer 
function ImDrawList:AddQuadFilled(p1, p2, p3, p4, col) end

---@param p1 Vector2 
---@param p2 Vector2 
---@param p3 Vector2 
---@param p4 Vector2 
---@param col integer 
---@param thickness number 
---@param numSegments integer? 
function ImDrawList:AddBezierCubic(p1, p2, p3, p4, col, thickness, numSegments) end

---@param p1 Vector2 
---@param p2 Vector2 
---@param p3 Vector2 
---@param col integer 
---@param thickness number 
---@param numSegments integer? 
function ImDrawList:AddBezierQuadratic(p1, p2, p3, col, thickness, numSegments) end

---@param p1 Vector2 
---@param p2 Vector2 
---@param p3 Vector2 
---@param col integer 
---@param thickness number? 
function ImDrawList:AddTriangle(p1, p2, p3, col, thickness) end

---@param p1 Vector2 
---@param p2 Vector2 
---@param p3 Vector2 
---@param col integer 
function ImDrawList:AddTriangleFilled(p1, p2, p3, col) end

function ImDrawList:PathClear() end

---@param pos Vector2 
function ImDrawList:PathLineTo(pos) end

---@param col integer 
---@param flags integer? 
function ImDrawList:PathStroke(col, flags) end

---@param col integer 
---@param flags integer 
---@param thickness number? 
function ImDrawList:PathStroke(col, flags, thickness) end

---@param center Vector2 
---@param radius number 
---@param aMin number 
---@param aMax number 
---@param numSegments integer? 
function ImDrawList:PathArcTo(center, radius, aMin, aMax, numSegments) end

---@param center Vector2 
---@param radius number 
---@param aMinOf12 integer Minimum indices into the 12-step circle approximation
---@param aMaxOf12 integer Maximum indices into the 12-step circle approximation
function ImDrawList:PathArcToFast(center, radius, aMinOf12, aMaxOf12) end

---@param col integer 
function ImDrawList:PathFillConcave(col) end

---@param rectMin Vector2 
---@param rectMax Vector2 
---@param rounding number? 
function ImDrawList:PathRect(rectMin, rectMax, rounding) end

---@param rectMin Vector2 
---@param rectMax Vector2 
---@param rounding number 
---@param flags integer? 
function ImDrawList:PathRect(rectMin, rectMax, rounding, flags) end

---@param col integer 
function ImDrawList:PathFillConvex(col) end

---@param p2 Vector2 
---@param p3 Vector2 
---@param p4 Vector2 
---@param numSegments integer? 
function ImDrawList:PathBezierCubicCurveTo(p2, p3, p4, numSegments) end

---@param p2 Vector2 
---@param p3 Vector2 
---@param numSegments integer? 
function ImDrawList:PathBezierQuadraticCurveTo(p2, p3, numSegments) end

---@param center Vector2 
---@param radius Vector2 
---@param rot number 
---@param aMin number 
---@param aMax number 
---@param numSegments integer? 
function ImDrawList:PathEllipticalArcTo(center, radius, rot, aMin, aMax, numSegments) end

---@param min Vector2 
---@param max Vector2 
---@param intersectWithCurrentClipRect boolean? 
function ImDrawList:PushClipRect(min, max, intersectWithCurrentClipRect) end

function ImDrawList:PopClipRect() end
